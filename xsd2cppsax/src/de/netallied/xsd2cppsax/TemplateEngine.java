package de.netallied.xsd2cppsax;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.SortedSet;
import java.util.TreeSet;

import org.apache.xerces.xs.XSAttributeUse;
import org.apache.xerces.xs.XSComplexTypeDefinition;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSModelGroup;
import org.apache.xerces.xs.XSObject;
import org.apache.xerces.xs.XSParticle;
import org.apache.xerces.xs.XSSimpleTypeDefinition;
import org.apache.xerces.xs.XSTypeDefinition;

import de.netallied.xsd2cppsax.TypeMapping.TypeMap;
import de.netallied.xsd2cppsax.statemachine.StateMachineNode;
import de.netallied.xsd2cppsax.statemachine.StateMachineRootNode;

/**
 * Provides methods to fill in code templates.
 * 
 */
public class TemplateEngine {

    /**
     * Creates code to check if required attributes are present.
     * 
     * @param cppElementName
     *            C++ name of element.
     * @param element
     *            Element of which attributes shall be checked.
     * @param dataProvider
     *            DataProvider.
     * @return C++ Code.
     */
    protected static String attributesCheckRequiredPresent(String cppElementName, XSElementDeclaration element,
            IGenerationDataProvider dataProvider) {
        String code = new String();
        Config config = dataProvider.getConfig();

        List<XSAttributeUse> attributes = Util.collectAttributeUses(element);
        for (XSAttributeUse attrUse : attributes) {
            if (attrUse.getRequired()) {
                XSSimpleTypeDefinition attrType = Util.getType(attrUse);
                String codeTmpl = config.getTemplateAttributeCheckRequiredPresent();
                if (codeTmpl.contains(Constants.TMPL_ATTR_NOT_PRESENT_CHECK)) {
                    if (Util.findVariety(attrType) == Variety.ATOMIC) {
                        if (Util.hasFacetEnum(attrType)) {
                            codeTmpl = codeTmpl.replace(Constants.TMPL_ATTR_NOT_PRESENT_CHECK, config
                                    .getTemplateAttributePresentCheckEnumAtomic());
                            String cppEnumTypeName = dataProvider.getEnumOrUnionNameCreator().createEnumTypeName(
                                    attrType, null);
                            codeTmpl = fillInEnumTemplate(codeTmpl, cppEnumTypeName, attrType, null, 0, dataProvider);
                        } else if (Util.isStringType(attrType, config)) {
                            codeTmpl = codeTmpl.replace(Constants.TMPL_ATTR_NOT_PRESENT_CHECK, config
                                    .getTemplateAttributePresentCheckStringAtomic());
                        }
                    }
                }
                code += fillInTemplate(codeTmpl, cppElementName, element, attrUse, null, attrType, null, dataProvider);
            }
        }

        return code;
    }

    /**
     * Creates code to initialize objects in an attributes struct.
     * 
     * @param element
     *            Element of which attributes shall be processed.
     * @param dataProvider
     *            DataProvider.
     * @return Code to be inserted in template.
     */
    protected static String attributesInitObjects(XSElementDeclaration element, IGenerationDataProvider dataProvider) {
        String code = new String();
        Config config = dataProvider.getConfig();
        XSComplexTypeDefinition complexTypeDefi = Util.getComplexType(element.getTypeDefinition());
        if (complexTypeDefi != null) {
            List<XSAttributeUse> attributeUses = Util.objectListToList(complexTypeDefi.getAttributeUses());
            for (XSAttributeUse attrUse : attributeUses) {
                if (Util.isAttributeInitializationRequired(attrUse, dataProvider.getConfig())) {
                    XSSimpleTypeDefinition attrType = Util.getType(attrUse);
                    String codeTmpl = dataProvider.getConfig().getTemplateAttributeInitObject();

                    if (codeTmpl.contains(Constants.TMPL_ATTR_INIT_OBJECT)) {
                        boolean hasDefaultVal = Util.hasDefaultValue(attrUse);
                        String constraintValue = attrUse.getConstraintValue();
                        String attrValue = null;

                        if (codeTmpl.contains(Constants.TMPL_ATTR_INIT_OBJECT_SET_PRESENT)) {
                            String setPresent = null;
                            if (hasDefaultVal) {
                                setPresent = Constants.TMPL_INDENT + Constants.TMPL_ATTR_PRESENT_SET;
                            } else {
                                setPresent = "";
                            }
                            codeTmpl = codeTmpl.replace(Constants.TMPL_ATTR_INIT_OBJECT_SET_PRESENT, setPresent);
                        }

                        switch (Util.findVariety(attrType)) {
                        case UNION:
                            if (hasDefaultVal) {
                                String unionDefault = config.getTemplateAttributeInitObjectUnionDefault();
                                if (unionDefault.contains(Constants.TMPL_ATTR_INIT_OBJECT_DEFAULT_VAL)) {
                                    unionDefault = unionDefault.replace(Constants.TMPL_ATTR_INIT_OBJECT_DEFAULT_VAL,
                                            "\"" + constraintValue + "\"");
                                }
                                if (unionDefault.contains(Constants.TMPL_ATTR_INIT_OBJECT_DEFAULT_VAL_LENGTH)) {
                                    unionDefault = unionDefault.replace(
                                            Constants.TMPL_ATTR_INIT_OBJECT_DEFAULT_VAL_LENGTH, String
                                                    .valueOf(constraintValue.length()));
                                }
                                unionDefault = fillInUnionTemplate(unionDefault, attrType, dataProvider);
                                attrValue = config.getTemplateAttributeInitObjectUnionPreDefault();
                                attrValue += config.getTemplateAttributeInitObjectNoDefaultLHS() + unionDefault;
                            } else {
                                CppEnumNameCreator cppEnumOrUnionNameCreator = dataProvider.getEnumOrUnionNameCreator();
                                String unionType = cppEnumOrUnionNameCreator.createUnionTypeName(attrType, dataProvider
                                        .getElementStack());
                                attrValue = config.getTemplateAttributeInitObjectNoDefaultLHS() + unionType + "();";
                            }
                            break;
                        case LIST:
                            if (hasDefaultVal) {
                                XSSimpleTypeDefinition itemType = attrType.getItemType();
                                String xsdType = Util.findXSDSimpleTypeString(itemType, config);
                                String listType;
                                if (Util.findVariety(itemType) == Variety.UNION) {
                                    listType = dataProvider.getConfig()
                                            .getTemplateUnionAttributeListTypeConversionNoItemValidation();
                                    listType = fillInUnionTemplate(listType, itemType, dataProvider);
                                } else {
                                    listType = config.getTypeMapping().get(xsdType)
                                            .getAttrListTypeConversionNoItemValidation();
                                }
                                String cppElementName = dataProvider.getElementNameMapping().get(element).cppElementName;
                                listType = fillInTypeMappingTemplate(listType, cppElementName, null, dataProvider);
                                // TODO use code templates for these strings
                                if (listType.contains("attributeValue")) {
                                    listType = listType.replace("attributeValue", "\"" + constraintValue + "\"");
                                }
                                attrValue = listType;

                                String preInit = config.getTypeMapping().get(xsdType).getInitializePreList();
                                if (preInit != null) {
                                    attrValue = preInit + attrValue;
                                }

                            } else {
                                attrValue = config.getTemplateAttributeInitObjectNoDefaultLHS()
                                        + dataProvider.findCorrectCppTypeForAttribute(attrType) + "();";
                            }
                            break;
                        case ATOMIC:
                            String cppAtomicType = Util.findXSDSimpleTypeString(attrType, config);
                            String initialize = config.getTypeMapping().get(cppAtomicType).getInitialize();
                            if (initialize != null) {
                                String value = null;
                                if (hasDefaultVal) {
                                    value = constraintValue;
                                } else {
                                    value = "";
                                }
                                attrValue = config.getTemplateAttributeInitObjectNoDefaultLHS()
                                        + TemplateEngine.fillInInitializationTemplate(initialize, value);
                            } else {
                                attrValue = config.getTemplateAttributeInitObjectNoDefaultLHS() + "0";
                            }
                            String preInit = config.getTypeMapping().get(cppAtomicType).getInitializePreAtomic();
                            if (preInit != null && hasDefaultVal) {
                                attrValue = preInit + attrValue;
                            }
                            attrValue += ";";

                            break;
                        }
                        codeTmpl = codeTmpl.replace(Constants.TMPL_ATTR_INIT_OBJECT, attrValue);
                    }
                    code += fillInTemplate(codeTmpl, null, element, attrUse, null, attrType, null, dataProvider);
                }
            }
        }
        return code;
    }

    /**
     * Fills in a code template related to coherency test.
     * 
     * @param tmpl
     *            Code template.
     * @param dataProvider
     *            Generation data provider.
     * @return Filled in code template
     */
    public static String fillInCoherencyTestTemplate(String tmpl, IGenerationDataProvider dataProvider) {
        Config config = dataProvider.getConfig();

        if (tmpl.contains(Constants.TMPL_COHERENCY_TEST_ERROR_HANDLER)) {
            tmpl = tmpl.replace(Constants.TMPL_COHERENCY_TEST_ERROR_HANDLER, config.getCoherencyTestErrorHandlerName());
        }
        if (tmpl.contains(Constants.TMPL_COHERENCY_TEST_ID_COUNTER_MAP)) {
            tmpl = tmpl
                    .replace(Constants.TMPL_COHERENCY_TEST_ID_COUNTER_MAP, config.getCoherencyTestIdCounterMapName());
        }
        if (tmpl.contains(Constants.TMPL_COHERENCY_TEST_COUNT_ATTRIBUTE)) {
            tmpl = tmpl.replace(Constants.TMPL_COHERENCY_TEST_COUNT_ATTRIBUTE, config
                    .getCoherencyTestCountAttributeMemberName());
        }
        if (tmpl.contains(Constants.TMPL_COHERENCY_TEST_LIST_COUNT)) {
            tmpl = tmpl.replace(Constants.TMPL_COHERENCY_TEST_LIST_COUNT, config.getCoherencyTestListCountMemberName());
        }

        return tmpl;
    }

    /**
     * Fills in a template about complex validation and particles related to
     * current element (e.g. siblings or children).
     * 
     * @param tmpl
     *            Template to fill in. Don't pass a complete function template,
     *            just the particle specific part!
     * @param particle
     *            Particle which provides data to be inserted in template.
     * @param config
     *            Configuration.
     * @return Filled in template.
     */
    public static String fillInComplexValidationParticleTemplate(String tmpl, XSParticle particle, Config config) {
        if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STRUCT_MEMBER_SIBLING_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STRUCT_MEMBER_SIBLING_NAME, Util
                    .createComplexValidationDataStructMemberName(particle.getTerm(), config));
        }
        if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_MIN_OCCURENCE)) {
            tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_MIN_OCCURENCE, String.valueOf(particle.getMinOccurs()));
        }
        if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_SIBLING_NAME)) {
            String siblingName = "";
            if (particle.getTerm() != null && particle.getTerm().getName() != null) {
                siblingName = particle.getTerm().getName();
            }
            tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_SIBLING_NAME, siblingName);
        }
        return tmpl;
    }

    /**
     * Returns given complex type validation related template ready to print.
     * 
     * @param tmpl
     *            Template to process.
     * @param cppElementName
     *            C++ element name.
     * @param cppValidationDataStructType
     *            C++ type name of validation data struct.
     * @param complexType
     *            XSD type of element.
     * @param element
     *            XSD element.
     * @param sm
     *            State machine of parent element or null.
     * @param dataProvider
     *            DataProvider.
     * @return Filled in code template.
     */
    public static String fillInComplexValidationTemplate(String tmpl, String cppElementName,
            String cppValidationDataStructType, XSComplexTypeDefinition complexType, XSElementDeclaration element,
            StateMachineRootNode sm, IGenerationDataProvider dataProvider) {

        XSModelGroup modelGroup = null;
        if (complexType != null) {
            if (complexType.getParticle() != null) {
                if (complexType.getParticle().getTerm() instanceof XSModelGroup) {
                    modelGroup = (XSModelGroup) complexType.getParticle().getTerm();
                }
            }
        }
        XSParticle particle = null;
        if (modelGroup != null && modelGroup.getParticles() != null) {
            for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
                XSObject particleObject = modelGroup.getParticles().item(i);
                if (particleObject instanceof XSParticle) {
                    XSParticle currentParticle = (XSParticle) particleObject;
                    if (currentParticle.getTerm() instanceof XSElementDeclaration) {
                        XSElementDeclaration particleElement = (XSElementDeclaration) currentParticle.getTerm();
                        if (particleElement.getName().equals(element.getName())) {
                            particle = currentParticle;
                            break;
                        }
                    }
                }
            }
        }

        Config config = dataProvider.getConfig();
        int iterationCounter = 0;
        while (tmpl.contains(Constants.TEMPLATE_DELIMITER_COMPLEX_VALIDATION)) {
            iterationCounter++;
            if (iterationCounter > config.getMaxTemplateResolvingIterations()) {
                System.err.println("********************************************");
                System.err.println("Could not resolve template:");
                System.err.println(fillInTemplate(tmpl, cppElementName, null, null, null, null, null, dataProvider));
                System.err.println("********************************************");
                break;
            }

            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STRUCT_TYPE)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STRUCT_TYPE, cppValidationDataStructType);
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STRUCT_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STRUCT_NAME, config
                        .getComplexValidationDataStructVariableName());
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_PARENT_STRUCT_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_PARENT_STRUCT_NAME, config
                        .getComplexValidationDataParentStructVariableName());
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STRUCT_MEMBER)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STRUCT_MEMBER, Util
                        .createComplexValidationDataStructMemberName(element, config));
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_CHECK_MAX_OCCURENCE)) {
                String maxOccCheck = config.getTemplateComplexValidationCheckMaxOccurence();
                if (particle == null || (particle != null && particle.getMaxOccursUnbounded())) {
                    maxOccCheck = "";
                }
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_CHECK_MAX_OCCURENCE, maxOccCheck);
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_GET_VALIDATION_DATA)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_GET_VALIDATION_DATA, config
                        .getTemplateComplexValidationGetTopValidationData());
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_DELETE_VALIDATION_DATA)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_DELETE_VALIDATION_DATA, config
                        .getTemplateComplexValidationDeleteValidationData());
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_GET_PARENT_VALIDATION_DATA)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_GET_PARENT_VALIDATION_DATA, config
                        .getTemplateComplexValidationGetTopParentValidationData());
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_INCREMENT_OCCURENCE)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_INCREMENT_OCCURENCE, config
                        .getTemplateComplexValidationIncrementOccurence());
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_MAX_OCCURENCE)) {
                int maxOccurence = 0;
                if (particle != null) {
                    maxOccurence = particle.getMaxOccurs();
                }
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_MAX_OCCURENCE, String.valueOf(maxOccurence));
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_CHECK_MIN_OCCURENCE_OF_CHILDREN)) {
                String childrenCheck = "";
                if (modelGroup != null && modelGroup.getParticles() != null) {
                    switch (modelGroup.getCompositor()) {
                    case XSModelGroup.COMPOSITOR_ALL:
                    case XSModelGroup.COMPOSITOR_SEQUENCE:
                        for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
                            XSObject item = modelGroup.getParticles().item(i);
                            if (item instanceof XSParticle) {
                                XSParticle child = (XSParticle) item;
                                if (child.getMinOccurs() == 0) {
                                    continue;
                                }
                                String particleTmpl = config.getTemplateComplexValidationCheckMinOccurencOfChildren();
                                childrenCheck += fillInComplexValidationParticleTemplate(particleTmpl, child, config);
                            }
                        }
                        break;
                    case XSModelGroup.COMPOSITOR_CHOICE:
                        boolean allChildrenHaveMinOccurs = true;
                        for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
                            XSObject item = modelGroup.getParticles().item(i);
                            if (item instanceof XSParticle) {
                                XSParticle child = (XSParticle) item;
                                if (child.getMinOccurs() == 0) {
                                    allChildrenHaveMinOccurs = false;
                                    continue;
                                }
                                String particleTmpl = config
                                        .getTemplateComplexValidationChoiceCheckMinOccurencOfChildren();
                                childrenCheck += fillInComplexValidationParticleTemplate(particleTmpl, child, config);
                            }
                        }
                        if (allChildrenHaveMinOccurs) {
                            childrenCheck += config.getTemplateComplexValidationChoiceCheckOneChildPresent();
                            if (childrenCheck.contains(Constants.TMPL_COMPLEX_VALI_CHOICE_ONE_CHILD_PER_CHILD)) {
                                for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
                                    XSObject item = modelGroup.getParticles().item(i);
                                    if (item instanceof XSParticle) {
                                        XSParticle child = (XSParticle) item;
                                        String perChild = config
                                                .getTemplateComplexValidationChoiceCheckOneChildPresentPerChild();
                                        if (i != modelGroup.getParticles().getLength() - 1) {
                                            perChild += " && " + Constants.TMPL_CONTINUE_LOOP;
                                        }
                                        childrenCheck = childrenCheck.replace(
                                                Constants.TMPL_COMPLEX_VALI_CHOICE_ONE_CHILD_PER_CHILD, perChild);
                                        childrenCheck = fillInComplexValidationParticleTemplate(childrenCheck, child,
                                                config);

                                        if (childrenCheck.contains(Constants.TMPL_CONTINUE_LOOP)) {
                                            childrenCheck = childrenCheck.replace(Constants.TMPL_CONTINUE_LOOP,
                                                    Constants.TMPL_COMPLEX_VALI_CHOICE_ONE_CHILD_PER_CHILD);
                                        }
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_CHECK_MIN_OCCURENCE_OF_CHILDREN, childrenCheck);
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_CHECK_SIBLINGS)) {
                String siblingsCheck = "";
                if (modelGroup != null && modelGroup.getParticles() != null) {
                    switch (modelGroup.getCompositor()) {
                    case XSModelGroup.COMPOSITOR_SEQUENCE:
                        List<XSParticle> previousSiblings = new ArrayList<XSParticle>();
                        List<XSParticle> followingSiblings = new ArrayList<XSParticle>();
                        Util.splitParticlesForSequence(modelGroup, particle, previousSiblings, followingSiblings);
                        for (int i = previousSiblings.size() - 1; i >= 0; i--) {
                            XSParticle prevSib = previousSiblings.get(i);
                            if (prevSib.getMinOccurs() == 0) {
                                continue;
                            }
                            String particleTmpl = config.getTemplateComplexValidationSequCheckPrev();
                            siblingsCheck += fillInComplexValidationParticleTemplate(particleTmpl, prevSib, config);
                            break;
                        }
                        for (XSParticle nextSib : followingSiblings) {
                            String particleTmpl = config.getTemplateComplexValidationSequCheckNext();
                            siblingsCheck += fillInComplexValidationParticleTemplate(particleTmpl, nextSib, config);
                        }
                        break;
                    case XSModelGroup.COMPOSITOR_CHOICE:
                        List<XSParticle> siblings = Util.splitParticlesForChoice(modelGroup, particle);
                        for (XSParticle sibling : siblings) {
                            String particleTmpl = config.getTemplateComplexValidationChoiceCheckSiblilngs();
                            siblingsCheck += fillInComplexValidationParticleTemplate(particleTmpl, sibling, config);
                        }
                        break;
                    }
                }
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_CHECK_SIBLINGS, siblingsCheck);
            }

            // state machine
            if (sm != null) {
                if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE_END)) {
                    tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE_END, config
                            .getTemplateComplexValidationCheckStateMachineEnd());
                }
                if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE)) {
                    tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE, config
                            .getTemplateComplexValidationCheckStateMachine());
                }
                if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_SET_STATE_MACHINE_STATE)) {
                    tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_SET_STATE_MACHINE_STATE, config
                            .getTemplateComplexValidationSetStateMachineState());
                }
                if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_STRUCT_MEMBER)) {
                    tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_STRUCT_MEMBER, config
                            .getComplexValidationStateMachineStructMember());
                }
                if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_START_STATE)) {
                    List<StateMachineNode> startNodes = sm.findNodes(Constants.STATE_MACHINE_ROOT_NODE_NAME);
                    tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_START_STATE, String
                            .valueOf(startNodes.get(0).getStateID()));
                }
                if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_END_STATE)) {
                    List<StateMachineNode> endNodes = sm.findNodes(Constants.STATE_MACHINE_END_NODE_NAME);
                    tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_END_STATE, String.valueOf(endNodes
                            .get(0).getStateID()));
                }
                if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_CURRENT_STATE)) {
                    List<StateMachineNode> nodes = sm.findNodes(element.getName());
                    tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_CURRENT_STATE, String.valueOf(nodes
                            .get(0).getStateID()));
                }
                if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_CHECK_PER_STATE)
                        || tmpl.contains(Constants.TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE_END_PER_STATE)) {
                    boolean handleEnd = tmpl.contains(Constants.TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE_END_PER_STATE);
                    List<StateMachineNode> nodes = null;
                    if (!handleEnd) {
                        nodes = sm.findNodes(element.getName());
                    } else {
                        nodes = sm.findNodes(Constants.STATE_MACHINE_END_NODE_NAME);
                    }
                    SortedSet<String> prevStates = new TreeSet<String>();
                    if (config.getDebug()) {
                        System.out.println("***************************************");
                        System.out.println("prevs for element: " + nodes.get(0).getName());
                    }
                    for (StateMachineNode node : nodes) {
                        for (StateMachineNode prevNode : node.getPrecedingStates()) {
                            prevStates.add(prevNode.getStateID());
                            if (config.getDebug()) {
                                System.out.println("  " + prevNode.getName());
                            }
                        }
                    }
                    if (config.getDebug()) {
                        System.out.println("***************************************");
                    }

                    Iterator<String> iterator = prevStates.iterator();
                    while (iterator.hasNext()) {
                        String stateID = iterator.next();
                        String replaceTemplate = null;
                        if (!handleEnd) {
                            replaceTemplate = config.getTemplateComplexValidationCheckStateMachinePerState();
                        } else {
                            replaceTemplate = config.getTemplateComplexValidationCheckStateMachineEndPerState();
                        }
                        if (iterator.hasNext()) {
                            replaceTemplate += " || " + Constants.TMPL_CONTINUE_LOOP;
                        }
                        if (!handleEnd) {
                            tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_CHECK_PER_STATE,
                                    replaceTemplate);
                        } else {
                            tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE_END_PER_STATE,
                                    replaceTemplate);
                        }
                        String perState = String.valueOf(stateID);
                        if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_PREV_STATE)) {
                            tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_PREV_STATE, perState);
                        }
                        if (tmpl.contains(Constants.TMPL_CONTINUE_LOOP)) {
                            if (!handleEnd) {
                                tmpl = tmpl.replace(Constants.TMPL_CONTINUE_LOOP,
                                        Constants.TMPL_COMPLEX_VALI_STATE_MACHINE_CHECK_PER_STATE);
                            } else {
                                tmpl = tmpl.replace(Constants.TMPL_CONTINUE_LOOP,
                                        Constants.TMPL_COMPLEX_VALI_CHECK_STATE_MACHINE_END_PER_STATE);
                            }
                        }
                    }
                }

            }

        }
        return tmpl;
    }

    /**
     * Returns given enum related template ready to print.
     * 
     * @param tmpl
     *            Enum related template to process.
     * @param cppEnumTypeName
     *            Name of C++ enum type.
     * @param simpleType
     *            XSD type representing enum.
     * @param sortedEnumValues
     *            Sorted XSD enum values.
     * @param enumValue
     *            Number of enum value to handle.
     * @param dataProvider
     *            DataProvider.
     * @return Filled in code template.
     */
    public static String fillInEnumTemplate(String tmpl, String cppEnumTypeName, XSSimpleTypeDefinition simpleType,
            List<String> sortedEnumValues, int enumValue, IGenerationDataProvider dataProvider) {

        Config config = dataProvider.getConfig();
        int iterationCounter = 0;
        while (tmpl.contains(Constants.TEMPLATE_DELIMITER_ENUM)) {
            iterationCounter++;
            if (iterationCounter > config.getMaxTemplateResolvingIterations()) {
                System.err.println("********************************************");
                System.err.println("Could not resolve template:");
                System.err.println(fillInTemplate(tmpl, null, null, null, null, null, null, dataProvider));
                System.err.println("********************************************");
                break;
            }

            if (tmpl.contains(Constants.TMPL_ENUM_CPP_TYPE_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_CPP_TYPE_NAME, cppEnumTypeName);
            }
            if (tmpl.contains(Constants.TMPL_ENUM_MAP_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_MAP_NAME, Util.createEnumMapName(cppEnumTypeName, config));
            }
            if (tmpl.contains(Constants.TMPL_ENUM_COUNT)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_COUNT, Util.createEnumCountName(cppEnumTypeName, config));
            }
            if (tmpl.contains(Constants.TMPL_ENUM_MAP_ENTRY)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_MAP_ENTRY, config.getTemplateEnumMapEntry());
            }
            if (tmpl.contains(Constants.TMPL_ENUM_MAP_ENTRY_TYPE)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_MAP_ENTRY_TYPE, config.getTemplateEnumMapEntryType());
            }
            if (tmpl.contains(Constants.TMPL_ENUM_MAP_PAIR_TYPE)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_MAP_PAIR_TYPE, config.getEnumMapPairType());
            }
            if (tmpl.contains(Constants.TMPL_ENUM_BASE_TYPE_VALUE)) {
                String xsdEnumValue = sortedEnumValues.get(enumValue);
                if (Util.isFloatType(simpleType, config)) {
                    double tmp = Double.parseDouble(xsdEnumValue);
                    xsdEnumValue = String.valueOf(tmp);

                    String cppBaseType = Util.findCorrectCppAtomicType(simpleType, config);
                    if (cppBaseType.equals("float")) {
                        xsdEnumValue += "f";
                    }
                } else if (Util.isStringType(simpleType, config)) {
                    xsdEnumValue = Util.calculateHash(xsdEnumValue);
                }
                tmpl = tmpl.replace(Constants.TMPL_ENUM_BASE_TYPE_VALUE, xsdEnumValue);
            }
            if (tmpl.contains(Constants.TMPL_ENUM_CPP_BASE_TYPE)) {
                String cppBaseType = null;
                if (Util.isStringType(simpleType, config)) {
                    cppBaseType = Constants.ENUM_CPP_BASE_TYPE_FOR_STRINGS;
                } else {
                    cppBaseType = Util.findCorrectCppAtomicType(simpleType, config);
                }
                tmpl = tmpl.replace(Constants.TMPL_ENUM_CPP_BASE_TYPE, cppBaseType);
            }
            if (tmpl.contains(Constants.TMPL_ENUM_VALUE)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_VALUE, Util.createEnumValueName(cppEnumTypeName,
                        sortedEnumValues, enumValue, simpleType, config));
            }
            if (tmpl.contains(Constants.TMPL_ENUM_DATA_ATOMIC_XSD_2_CPP)) {
                String xsdTypeString = Util.findXSDSimpleTypeString(simpleType, config);
                String cppCode = config.getTypeMapping().get(xsdTypeString).getEnumDataAtomicTypeConversion();
                cppCode = TemplateEngine.fillInTypeMappingTemplate(cppCode, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_ENUM_DATA_ATOMIC_XSD_2_CPP, cppCode);
            }
            if (tmpl.contains(Constants.TMPL_ENUM_FUNC_TO_ENUM)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_FUNC_TO_ENUM, Util.createEnumFuncNameToEnum(cppEnumTypeName,
                        config));
            }
            if (tmpl.contains(Constants.TMPL_ENUM_FUNC_DATA_PREFIX)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_FUNC_DATA_PREFIX, Util.createEnumFuncNameDataPrefix(
                        cppEnumTypeName, config));
            }
            if (tmpl.contains(Constants.TMPL_ENUM_FUNC_CHAR_DATA)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_FUNC_CHAR_DATA, Util.createEnumFuncNameCharData(
                        cppEnumTypeName, config));
            }
            if (tmpl.contains(Constants.TMPL_ENUM_FUNC_DATA_END)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_FUNC_DATA_END, Util.createEnumFuncNameDataEnd(cppEnumTypeName,
                        config));
            }
            if (tmpl.contains(Constants.TMPL_ENUM_VALUE_NOT_PRESENT)) {
                tmpl = tmpl.replace(Constants.TMPL_ENUM_VALUE_NOT_PRESENT, Util.createEnumNotPresentName(
                        cppEnumTypeName, config));
            }

        }
        return tmpl;
    }

    /**
     * Fills in a hash finding related template.
     * 
     * @param tmpl
     *            Template to fill in.
     * @param cppElementName
     *            C++ element name.
     * @param element
     *            XSD element.
     * @param config
     *            Configuration.
     * @param typeIdMapping
     *            Mapping of XSD types to generated C++ type ID.
     * @return Processed template.
     */
    public static String fillInFindHashTemplate(String tmpl, String cppElementName, XSElementDeclaration element,
            Config config, Map<XSTypeDefinition, String> typeIdMapping) {

        if (tmpl.contains(Constants.TMPL_FINDHASH_TYPEID)) {
            tmpl = tmpl.replace(Constants.TMPL_FINDHASH_TYPEID, typeIdMapping.get(element.getTypeDefinition()));
        }
        if (tmpl.contains(Constants.TMPL_FINDHASH_GENERATED_HASH_VALUE)) {
            tmpl = tmpl.replace(Constants.TMPL_FINDHASH_GENERATED_HASH_VALUE, Util
                    .createElementNameHashIdentifier(cppElementName));
        }
        return tmpl;
    }

    /**
     * Fills in a value initialization code template.
     * 
     * @param tmpl
     *            Template to fill in.
     * @param value
     *            Initial value to set.
     * @return filled in template.
     */
    public static String fillInInitializationTemplate(String tmpl, String value) {
        if (tmpl.contains(Constants.TMPL_INITAL_VALUE)) {
            tmpl = tmpl.replace(Constants.TMPL_INITAL_VALUE, value);
        }
        return tmpl;
    }

    /**
     * Fills in C++ code templates related to simple type validation.
     * 
     * @param tmpl
     *            Code template to process.
     * @param simpleType
     *            XSD simple type current template belongs to.
     * @param config
     *            Configuration.
     * @param xsSimpleType2validationFunctionName
     *            Mapping of XSD type to C++ validation function name.
     * @return Filled in code template.
     */
    public static String fillInSimpleValidationTemplate(String tmpl, XSSimpleTypeDefinition simpleType, Config config,
            Map<XSSimpleTypeDefinition, String> xsSimpleType2validationFunctionName) {

        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_SPECIAL_STREAM_END_VALI)) {
            String code = "";
            if (Util.isSpecialStreamEndValidationRequired(simpleType)) {
                code = config.getTemplateSimpleValidationSpecialStreamEndVali();
            }
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_SPECIAL_STREAM_END_VALI, code);
        }

        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_SPECIAL_STREAM_END_VALI_HANDLE_ERROR)) {
            String code = "";
            if (Util.isSpecialStreamEndValidationRequired(simpleType)) {
                code = config.getTemplateSimpleValidationSpecialStreamEndValiHandleError();
            }
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_SPECIAL_STREAM_END_VALI_HANDLE_ERROR, code);
        }

        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_VALUE)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_VALUE, config
                    .getSimpleValidationFunctionValueParameterName());
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_LENGTH_VALUE)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_LENGTH_VALUE, config
                    .getSimpleValidationFunctionLengthParameterName());
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_MAX_EXCLUSIVE)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_MAX_EXCLUSIVE, simpleType
                    .getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MAXEXCLUSIVE));
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_MAX_INCLUSIVE)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_MAX_INCLUSIVE, simpleType
                    .getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MAXINCLUSIVE));
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_MIN_EXCLUSIVE)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_MIN_EXCLUSIVE, simpleType
                    .getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MINEXCLUSIVE));
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_MIN_INCLUSIVE)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_MIN_INCLUSIVE, simpleType
                    .getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MININCLUSIVE));
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_LENGTH)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_LENGTH, simpleType
                    .getLexicalFacetValue(XSSimpleTypeDefinition.FACET_LENGTH));
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_MIN_LENGTH)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_MIN_LENGTH, simpleType
                    .getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MINLENGTH));
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_MAX_LENGTH)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_MAX_LENGTH, simpleType
                    .getLexicalFacetValue(XSSimpleTypeDefinition.FACET_MAXLENGTH));
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_GET_COUNT_STRUCT_MEMBER)) {
            String funcName = xsSimpleType2validationFunctionName.get(simpleType);
            String getCountCode = null;
            if (funcName != null) {
                getCountCode = config.getTemplateSimpleValidationGetCountStructMemberValidation();
            } else {
                getCountCode = config.getTemplateSimpleValidationGetCountStructMemberNoValidation();
            }
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_GET_COUNT_STRUCT_MEMBER, getCountCode);
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_FUNCTION_NAME)) {
            String funcName = xsSimpleType2validationFunctionName.get(simpleType);
            if (funcName != null) {
                tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_FUNCTION_NAME, funcName);
            }
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_FUNCTION_NAME_STREAM)) {
            String funcName = xsSimpleType2validationFunctionName.get(simpleType);
            String streamFuncName = null;
            if (funcName != null) {
                streamFuncName = Util.createSimpleValidationStreamFunctionName(funcName, config);
                if (Util.findListItemType(simpleType) != null) {
                    streamFuncName = "&" + streamFuncName;
                }
            } else {
                streamFuncName = "0";
            }
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_FUNCTION_NAME_STREAM, streamFuncName);
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_FUNCTION_NAME_STREAM_END)) {
            String funcName = xsSimpleType2validationFunctionName.get(simpleType);
            String streamEndFuncName = null;
            if (funcName != null) {
                streamEndFuncName = Util.createSimpleValidationStreamEndFunctionName(funcName, config);
                if (Util.findListItemType(simpleType) != null) {
                    streamEndFuncName = "&" + streamEndFuncName;
                }
            } else {
                streamEndFuncName = "0";
            }
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_FUNCTION_NAME_STREAM_END, streamEndFuncName);
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_ITEM_TYPE_FUNCTION_NAME)) {
            XSSimpleTypeDefinition itemType = simpleType.getItemType();
            String funcName = xsSimpleType2validationFunctionName.get(itemType);
            if (funcName == null) {
                funcName = "0";
            } else {
                funcName = "&" + funcName;
            }
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_ITEM_TYPE_FUNCTION_NAME, funcName);
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_STREAM_COUNT_STRUCT_MEMBER)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_STREAM_COUNT_STRUCT_MEMBER, config
                    .getSimpleValidationStreamCountStructMember());
        }
        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_UPDATE_STREAM_COUNT)) {
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_UPDATE_STREAM_COUNT, config
                    .getTemplateSimpleValidationUpdateStreamCount());
        }
        if (tmpl.contains(Constants.TMPL_VALI_BLOCK_OPEN)) {
            tmpl = tmpl.replace(Constants.TMPL_VALI_BLOCK_OPEN, config.getTemplateComplexValidationBlockOpen());
        }
        if (tmpl.contains(Constants.TMPL_VALI_BLOCK_ELSE_RUN_TIME)) {
            tmpl = tmpl.replace(Constants.TMPL_VALI_BLOCK_ELSE_RUN_TIME, config
                    .getTemplateComplexValidationBlockElseRunTime());
        }
        if (tmpl.contains(Constants.TMPL_VALI_BLOCK_ELSE_COMPILE_TIME)) {
            tmpl = tmpl.replace(Constants.TMPL_VALI_BLOCK_ELSE_COMPILE_TIME, config
                    .getTemplateComplexValidationBlockElseCompileTime());
        }
        if (tmpl.contains(Constants.TMPL_VALI_BLOCK_CLOSE)) {
            tmpl = tmpl.replace(Constants.TMPL_VALI_BLOCK_CLOSE, config.getTemplateComplexValidationBlockClose());
        }

        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI_PCRE_COMPILER_OUTPUT)) {
            String output = "";
            String pattern = Util.collectPatternFacet(simpleType);

            // TODO make pattern set handling independent of COLLADA 1.5
            if (pattern.contains("[\\c-[:]]")) {
                pattern = pattern.replace("[\\c-[:]]", config.getPcreNameCharactersWithoutColon());
            }
            if (pattern.contains("[\\i-[:]]")) {
                pattern = pattern.replace("[\\i-[:]]", config.getPcreInitialNameCharactersWithoutColon());
            }
            if (pattern.contains("[\\i-[:\\.]]")) {
                pattern = pattern.replace("[\\i-[:\\.]]", config.getPcreInitialNameCharactersWithoutColonAndDot());
            }

            if (pattern.contains("\\c")) {
                pattern = pattern.replace("\\c", config.getPcreNameCharacters());
            }
            if (pattern.contains("\\i")) {
                pattern = pattern.replace("\\i", config.getPcreInitialNameCharacters());
            }

            pattern = "^" + pattern + "$";
            String commandline = "pcre_compiler pattern \"" + pattern + "\"";
            try {
                Process proc = Runtime.getRuntime().exec(commandline);
                InputStream inputStream = proc.getInputStream();
                InputStreamReader inStreamReader = new InputStreamReader(inputStream);
                BufferedReader bufferdReader = new BufferedReader(inStreamReader);
                String line = null;
                while ((line = bufferdReader.readLine()) != null) {
                    output += line + "#nl#";
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI_PCRE_COMPILER_OUTPUT, output);
        }

        return tmpl;
    }

    /**
     * Returns given template ready to print.
     * 
     * Many of the parameters may be null.
     * 
     * @note {@link Util#findCorrectCppAtomicType(XSTypeDefinition)} has a copy
     *       of some of this code.
     * 
     * @param tmpl
     *            Template to process.
     * @param cppElementName
     *            C++ element name to fill into template.
     * @param element
     *            XSD representation of element.
     * @param attrUse
     *            XSD attribute to fill into template.
     * @param dataMethodName
     *            Name of data method to be implemented by subclasses.
     * @param type
     *            XSD Type to fill in to template.
     * @param simpleTypeValiTmpl
     *            Code template to fill in for simple type validation.
     * @param dataProvider
     *            DataProvider.
     * @return Processed template.
     */
    public static String fillInTemplate(String tmpl, String cppElementName, XSElementDeclaration element,
            XSAttributeUse attrUse, String dataMethodName, XSTypeDefinition type, String simpleTypeValiTmpl,
            IGenerationDataProvider dataProvider) {

        XSSimpleTypeDefinition simpleType = Util.findSimpleTypeDefinition(type);
        Variety variety = Util.findVariety(simpleType);
        XSSimpleTypeDefinition listType = null;
        if (variety == Variety.LIST) {
            listType = simpleType;
            simpleType = Util.findListItemType(simpleType);
        }
        String xsdType = Util.findXSDSimpleTypeString(simpleType, dataProvider.getConfig());

        if (tmpl.contains(Constants.TMPL_ATTRIBUTE_PARSING_SWITCH_DEFAULT)) {
            String code = null;
            if (Util.isUnknownAttributesMemberRequired(element.getTypeDefinition())) {
                code = dataProvider.getConfig().getTemplateValidateBeginSwitchDefaultUnknownAttributes();
            } else {
                code = dataProvider.getConfig().getTemplateValidateBeginSwitchDefault();
            }
            tmpl = tmpl.replace(Constants.TMPL_ATTRIBUTE_PARSING_SWITCH_DEFAULT, code);
        }

        if (variety == Variety.ATOMIC) {
            if (tmpl.contains(Constants.TMPL_PRE_ATTR_ATOMIC_XSD_2_CPP)) {
                String conversion = null;
                if (Util.hasFacetEnum(simpleType)) {
                    conversion = fillInEnumTemplate(dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getEnumAttrAtomicTypePreConversion(), dataProvider.getEnumOrUnionNameCreator()
                            .createEnumTypeName(simpleType, null), simpleType, null, 0, dataProvider);
                } else {
                    conversion = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getAttrAtomicTypePreConversion();
                }
                conversion = fillInTypeMappingTemplate(conversion, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_PRE_ATTR_ATOMIC_XSD_2_CPP, conversion);
            }
            if (tmpl.contains(Constants.TMPL_ATTR_ATOMIC_XSD_2_CPP)) {
                String conversion = null;
                if (Util.hasFacetEnum(simpleType)) {
                    conversion = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getEnumAttrAtomicTypeConversion();
                    conversion = fillInTypeMappingTemplate(conversion, null, null, dataProvider);
                    conversion = fillInEnumTemplate(conversion, dataProvider.getEnumOrUnionNameCreator()
                            .createEnumTypeName(simpleType, null), simpleType, null, 0, dataProvider);
                } else {
                    conversion = dataProvider.getConfig().getTypeMapping().get(xsdType).getAttrAtomicTypeConversion();
                }
                conversion = fillInTypeMappingTemplate(conversion, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_ATTR_ATOMIC_XSD_2_CPP, conversion);
            }
            if (tmpl.contains(Constants.TMPL_POST_ATTR_ATOMIC_XSD_2_CPP)) {
                String conversion = null;
                if (Util.hasFacetEnum(simpleType)) {
                    conversion = fillInEnumTemplate(dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getEnumAttrAtomicTypePostConversion(), dataProvider.getEnumOrUnionNameCreator()
                            .createEnumTypeName(simpleType, null), simpleType, null, 0, dataProvider);
                } else {
                    conversion = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getAttrAtomicTypePostConversion();
                }
                conversion = fillInTypeMappingTemplate(conversion, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_POST_ATTR_ATOMIC_XSD_2_CPP, conversion);
            }

            if (tmpl.contains(Constants.TMPL_PRE_DATA_ATOMIC_XSD_2_CPP)) {
                String replaceValue = null;
                if (Util.hasFacetEnum(simpleType) && Util.isStringType(simpleType, dataProvider.getConfig())) {
                    replaceValue = Constants.TMPL_TYPE_MAP_DEFAULT_PRE_ATTR_ATOMIC_XSD2CPP;
                } else {
                    replaceValue = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getDataAtomicTypePreConversion();
                }
                replaceValue = fillInTypeMappingTemplate(replaceValue, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_PRE_DATA_ATOMIC_XSD_2_CPP, replaceValue);
            }
            if (tmpl.contains(Constants.TMPL_DATA_ATOMIC_XSD_2_CPP)) {
                String replaceValue = dataProvider.getConfig().getTypeMapping().get(xsdType)
                        .getDataAtomicTypeConversion();
                replaceValue = fillInTypeMappingTemplate(replaceValue, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_DATA_ATOMIC_XSD_2_CPP, replaceValue);
            }
            if (tmpl.contains(Constants.TMPL_POST_DATA_ATOMIC_XSD_2_CPP)) {
                String replaceValue = null;
                if (Util.hasFacetEnum(simpleType) && Util.isStringType(simpleType, dataProvider.getConfig())) {
                    replaceValue = Constants.TMPL_TYPE_MAP_DEFAULT_POST_DATA_ATOMIC_XSD2CPP;
                } else {
                    replaceValue = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getDataAtomicTypePostConversion();
                }
                replaceValue = fillInTypeMappingTemplate(replaceValue, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_POST_DATA_ATOMIC_XSD_2_CPP, replaceValue);
            }

            if (tmpl.contains(Constants.TMPL_DATA_ATOMIC_DATA_METHOD_IMPL)) {
                TypeMap typeMap = dataProvider.getConfig().getTypeMapping().get(xsdType);
                String cppImpl = null;
                if (Util.isFacetPatternSupported(simpleType, dataProvider.getConfig())) {
                    cppImpl = typeMap.getDataAtomicDataMethodImplFacetPattern();
                } else {
                    cppImpl = typeMap.getDataAtomicDataMethodImpl();
                }
                if (cppImpl != null && cppImpl.length() > 0) {
                    cppImpl = fillInTypeMappingTemplate(cppImpl, null, null, dataProvider);
                    tmpl = tmpl.replace(Constants.TMPL_DATA_ATOMIC_DATA_METHOD_IMPL, cppImpl);
                } else {
                    tmpl = tmpl.replace(Constants.TMPL_DATA_ATOMIC_DATA_METHOD_IMPL,
                            Constants.TMPL_DATA_ATOMIC_DATA_METHOD_IMPL_DEFAULT);
                }
            }
        }

        if (variety == Variety.LIST) {
            if (tmpl.contains(Constants.TMPL_PRE_ATTR_LIST_XSD_2_CPP)) {
                String cppCode = dataProvider.getConfig().getTypeMapping().get(xsdType).getAttrListTypePreConversion();
                cppCode = fillInTypeMappingTemplate(cppCode, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_PRE_ATTR_LIST_XSD_2_CPP, cppCode);
            }
            if (tmpl.contains(Constants.TMPL_ATTR_LIST_XSD_2_CPP)) {
                String itemConversion = null;
                if (Util.findVariety(simpleType) == Variety.UNION) {
                    itemConversion = dataProvider.getConfig()
                            .getTemplateUnionAttributeListTypeConversionNoItemValidation();
                    itemConversion = fillInUnionTemplate(itemConversion, simpleType, dataProvider);
                } else {
                    itemConversion = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getAttrListTypeConversionNoItemValidation();
                }
                itemConversion = fillInTypeMappingTemplate(itemConversion, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_ATTR_LIST_XSD_2_CPP, itemConversion);
            }
            if (tmpl.contains(Constants.TMPL_ATTR_LIST_XSD_2_CPP_ITEM_VALIDATION)) {
                String itemConversionVali = null;
                if (Util.findVariety(simpleType) == Variety.UNION) {
                    itemConversionVali = dataProvider.getConfig()
                            .getTemplateUnionAttributeListTypeConversionItemValidation();
                    itemConversionVali = fillInUnionTemplate(itemConversionVali, simpleType, dataProvider);
                } else {
                    itemConversionVali = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getAttrListTypeConversionItemValidation();
                }
                itemConversionVali = fillInTypeMappingTemplate(itemConversionVali, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_ATTR_LIST_XSD_2_CPP_ITEM_VALIDATION, itemConversionVali);
                tmpl = fillInSimpleValidationTemplate(tmpl, listType, dataProvider.getConfig(), dataProvider
                        .getXsSimpleType2validationFunctionName());

            }
            if (tmpl.contains(Constants.TMPL_POST_ATTR_LIST_XSD_2_CPP)) {
                String cppCode = dataProvider.getConfig().getTypeMapping().get(xsdType).getAttrListTypePostConversion();
                cppCode = fillInTypeMappingTemplate(cppCode, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_POST_ATTR_LIST_XSD_2_CPP, cppCode);
            }

            if (tmpl.contains(Constants.TMPL_DATA_LIST_XSD_2_CPP_VALIDATION)) {
                if (Util.findVariety(simpleType) == Variety.UNION) {
                    String cppConversion = dataProvider.getConfig().getTemplateUnionDataListTypeConversionValidation();
                    cppConversion = fillInUnionTemplate(cppConversion, simpleType, dataProvider);
                    cppConversion = prepareSimpleTypeValidationTemplate(cppConversion, simpleType, cppElementName,
                            element, dataProvider);
                    tmpl = tmpl.replace(Constants.TMPL_DATA_LIST_XSD_2_CPP_VALIDATION, cppConversion);
                } else if (Util.hasFacetEnum(simpleType)) {
                    tmpl = tmpl.replace(Constants.TMPL_DATA_LIST_XSD_2_CPP_VALIDATION,
                            Constants.TMPL_DATA_LIST_XSD_2_CPP);
                } else {
                    String cppConversion = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getDataListTypeConversionValidation();
                    cppConversion = fillInTypeMappingTemplate(cppConversion, null, null, dataProvider);
                    cppConversion = prepareSimpleTypeValidationTemplate(cppConversion, listType, cppElementName,
                            element, dataProvider);
                    tmpl = tmpl.replace(Constants.TMPL_DATA_LIST_XSD_2_CPP_VALIDATION, cppConversion);
                }
            }
            if (tmpl.contains(Constants.TMPL_DATA_LIST_XSD_2_CPP)) {
                String cppConversion = null;
                if (Util.findVariety(simpleType) == Variety.UNION) {
                    cppConversion = dataProvider.getConfig().getTemplateUnionDataListTypeConversion();
                    cppConversion = fillInUnionTemplate(cppConversion, simpleType, dataProvider);
                } else if (Util.hasFacetEnum(simpleType)) {
                    cppConversion = dataProvider.getConfig().getTypeMapping().get(xsdType)
                            .getEnumDataListTypeConversion();
                    cppConversion = fillInTypeMappingTemplate(cppConversion, cppElementName, attrUse, dataProvider);
                    cppConversion = fillInEnumTemplate(cppConversion, dataProvider.getEnumOrUnionNameCreator()
                            .createEnumTypeName(simpleType, null), simpleType, null, 0, dataProvider);
                } else {
                    cppConversion = dataProvider.getConfig().getTypeMapping().get(xsdType).getDataListTypeConversion();
                }
                cppConversion = fillInTypeMappingTemplate(cppConversion, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_DATA_LIST_XSD_2_CPP, cppConversion);
            }
            if (tmpl.contains(Constants.TMPL_DATA_LIST_VALIDATE_END)) {
                String cppConversion = null;
                if (Util.findVariety(simpleType) == Variety.UNION) {
                    cppConversion = dataProvider.getConfig().getTemplateUnionDataListEnd();
                    cppConversion = fillInUnionTemplate(cppConversion, simpleType, dataProvider);
                } else {
                    cppConversion = dataProvider.getConfig().getTypeMapping().get(xsdType).getDataListEnd();
                }
                cppConversion = fillInTypeMappingTemplate(cppConversion, null, null, dataProvider);
                cppConversion = prepareSimpleTypeValidationTemplate(cppConversion, listType, cppElementName, element,
                        dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_DATA_LIST_VALIDATE_END, cppConversion);
            }
            if (tmpl.contains(Constants.TMPL_DATA_LIST_VALIDATE_END_VALIDATION)) {
                String cppConversion = null;
                if (Util.findVariety(simpleType) == Variety.UNION) {
                    cppConversion = dataProvider.getConfig().getTemplateUnionDataListEndValidation();
                    cppConversion = fillInUnionTemplate(cppConversion, simpleType, dataProvider);
                } else {
                    cppConversion = dataProvider.getConfig().getTypeMapping().get(xsdType).getDataListEndValidation();
                }
                cppConversion = fillInTypeMappingTemplate(cppConversion, null, null, dataProvider);
                cppConversion = prepareSimpleTypeValidationTemplate(cppConversion, listType, cppElementName, element,
                        dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_DATA_LIST_VALIDATE_END_VALIDATION, cppConversion);
            }
        }

        if (variety == Variety.UNION) {
            if (tmpl.contains(Constants.TMPL_UNION_ATTR_ATOMIC_XSD_2_CPP)) {
                String unionTmpl = dataProvider.getConfig().getTemplateUnionAttributeAtomicXsd2Cpp();
                unionTmpl = fillInUnionTemplate(unionTmpl, simpleType, dataProvider);
                unionTmpl = fillInTypeMappingTemplate(unionTmpl, cppElementName, attrUse, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_ATTR_ATOMIC_XSD_2_CPP, unionTmpl);
            }
            if (tmpl.contains(Constants.TMPL_UNION_ATTR_ATOMIC_PRE_XSD_2_CPP)) {
                String unionTmpl = dataProvider.getConfig().getTemplateUnionAttributeAtomicPreXsd2Cpp();
                unionTmpl = fillInUnionTemplate(unionTmpl, simpleType, dataProvider);
                unionTmpl = fillInTypeMappingTemplate(unionTmpl, cppElementName, attrUse, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_ATTR_ATOMIC_PRE_XSD_2_CPP, unionTmpl);
            }
            if (tmpl.contains(Constants.TMPL_UNION_ATTR_ATOMIC_POST_XSD_2_CPP)) {
                String unionTmpl = dataProvider.getConfig().getTemplateUnionAttributeAtomicPostXsd2Cpp();
                unionTmpl = fillInUnionTemplate(unionTmpl, simpleType, dataProvider);
                unionTmpl = fillInTypeMappingTemplate(unionTmpl, cppElementName, attrUse, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_ATTR_ATOMIC_POST_XSD_2_CPP, unionTmpl);
            }
            if (tmpl.contains(Constants.TMPL_UNION_DATA_ATOMIC_DATA_METHOD_IMPL)) {
                String unionTmpl = dataProvider.getConfig().getTemplateUnionDataAtomicDataMethodImpl();
                unionTmpl = fillInUnionTemplate(unionTmpl, simpleType, dataProvider);
                unionTmpl = fillInTypeMappingTemplate(unionTmpl, cppElementName, attrUse, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_DATA_ATOMIC_DATA_METHOD_IMPL, unionTmpl);
            }
            if (tmpl.contains(Constants.TMPL_UNION_DATA_ATOMIC_XSD2CPP)) {
                String unionTmpl = dataProvider.getConfig().getTemplateUnionDataAtomicXsd2Cpp();
                unionTmpl = fillInUnionTemplate(unionTmpl, simpleType, dataProvider);
                unionTmpl = fillInTypeMappingTemplate(unionTmpl, cppElementName, attrUse, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_DATA_ATOMIC_XSD2CPP, unionTmpl);
            }
            if (tmpl.contains(Constants.TMPL_UNION_DATA_ATOMIC_PRE_XSD2CPP)) {
                String unionTmpl = dataProvider.getConfig().getTemplateUnionDataAtomicPreXsd2Cpp();
                unionTmpl = fillInUnionTemplate(unionTmpl, simpleType, dataProvider);
                unionTmpl = fillInTypeMappingTemplate(unionTmpl, cppElementName, attrUse, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_DATA_ATOMIC_PRE_XSD2CPP, unionTmpl);
            }
            if (tmpl.contains(Constants.TMPL_UNION_DATA_ATOMIC_POST_XSD2CPP)) {
                String unionTmpl = dataProvider.getConfig().getTemplateUnionDataAtomicPostXsd2Cpp();
                unionTmpl = fillInUnionTemplate(unionTmpl, simpleType, dataProvider);
                unionTmpl = fillInTypeMappingTemplate(unionTmpl, cppElementName, attrUse, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_DATA_ATOMIC_POST_XSD2CPP, unionTmpl);
            }
        }

        if (tmpl.contains(Constants.TMPL_ATTR_INIT_OBJECTS)) {
            tmpl = tmpl.replace(Constants.TMPL_ATTR_INIT_OBJECTS, attributesInitObjects(element, dataProvider));
        }
        if (tmpl.contains(Constants.TMPL_ATTR_CHECK_REQUIRED_PRESENT)) {
            tmpl = tmpl.replace(Constants.TMPL_ATTR_CHECK_REQUIRED_PRESENT, attributesCheckRequiredPresent(
                    cppElementName, element, dataProvider));
        }

        if (tmpl.contains(Constants.TMPL_CPP_ATOMIC_TYPE)) {
            String cppType = null;
            if (Util.hasFacetEnum(simpleType)) {
                cppType = dataProvider.getEnumOrUnionNameCreator().createEnumTypeName(simpleType, null);
            } else {
                cppType = dataProvider.getConfig().getTypeMapping().get(xsdType).getAttrAtomicType();
            }
            cppType = fillInTypeMappingTemplate(cppType, null, null, dataProvider);
            tmpl = tmpl.replace(Constants.TMPL_CPP_ATOMIC_TYPE, cppType);
        }

        if (tmpl.contains(Constants.TMPL_SIMPLE_VALI)) {
            if (variety == Variety.LIST) {
                if (dataProvider.getXsSimpleType2validationFunctionName().get(listType) != null
                        && simpleTypeValiTmpl != null) {
                    simpleTypeValiTmpl = fillInSimpleValidationTemplate(simpleTypeValiTmpl, listType, dataProvider
                            .getConfig(), dataProvider.getXsSimpleType2validationFunctionName());
                } else {
                    simpleTypeValiTmpl = "";
                }
            } else {
                if (dataProvider.getXsSimpleType2validationFunctionName().get(simpleType) != null
                        && simpleTypeValiTmpl != null) {
                    simpleTypeValiTmpl = fillInSimpleValidationTemplate(simpleTypeValiTmpl, simpleType, dataProvider
                            .getConfig(), dataProvider.getXsSimpleType2validationFunctionName());
                } else {
                    simpleTypeValiTmpl = "";
                }
            }
            tmpl = tmpl.replace(Constants.TMPL_SIMPLE_VALI, simpleTypeValiTmpl);
        }

        if (tmpl.contains(Constants.TMPL_FPRINTF_PARSER_CLASS_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_FPRINTF_PARSER_CLASS_NAME, dataProvider.getConfig()
                    .getFPrintfParserClassName());
        }
        if (tmpl.contains(Constants.TMPL_FPRINTF_PARSER_FILE_MEMBER_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_FPRINTF_PARSER_FILE_MEMBER_NAME, dataProvider.getConfig()
                    .getFprintfParserFileMemberName());
        }
        if (tmpl.contains(Constants.TMPL_FPRINTF_PARSER_PRINT_FLOAT_TEMPLATE_METHOD_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_FPRINTF_PARSER_PRINT_FLOAT_TEMPLATE_METHOD_NAME, dataProvider
                    .getConfig().getFprintfParserPrintFloatTemplateMethodName());
        }
        if (tmpl.contains(Constants.TMPL_FPRINTF_PARSER_PRINT_FLOAT_METHOD_PARAMETER_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_FPRINTF_PARSER_PRINT_FLOAT_METHOD_PARAMETER_NAME, dataProvider
                    .getConfig().getFprintfParserPrintFloatMethodParameterName());
        }

        if (tmpl.contains(Constants.TMPL_ELEMENT_NAME)) {
            // note: use XSD Element Name here, NOT C++ Name
            tmpl = tmpl.replace(Constants.TMPL_ELEMENT_NAME, element.getName());
        }
        if (tmpl.contains(Constants.TMPL_ELEMENT_NAME_HASH)) {
            // note: use XSD Element Name here, NOT C++ Name
            tmpl = tmpl.replace(Constants.TMPL_ELEMENT_NAME_HASH, Util.createElementNameHashIdentifier(element
                    .getName()));
        }

        if (attrUse != null) {
            if (tmpl.contains(Constants.TMPL_ATTRIBUTE_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_ATTRIBUTE_NAME, Util.getAttributeName(attrUse, dataProvider
                        .getConfig()));
            }
            if (tmpl.contains(Constants.TMPL_ATTRIBUTE_NAME_HASH)) {
                tmpl = tmpl.replace(Constants.TMPL_ATTRIBUTE_NAME_HASH, Util.createAttributeNameHashIdentifier(Util
                        .getAttributeOriginalName(attrUse, dataProvider.getConfig())));
            }
            if (tmpl.contains(Constants.TMPL_ATTR_PRESENT_MEMBER)) {
                tmpl = tmpl.replace(Constants.TMPL_ATTR_PRESENT_MEMBER, dataProvider.getConfig()
                        .getAttributesPresentMemberName());
            }
            if (tmpl.contains(Constants.TMPL_ATTR_PRESENT_MASK)) {
                tmpl = tmpl.replace(Constants.TMPL_ATTR_PRESENT_MASK, Util.createAttributePresentMaskName(attrUse,
                        dataProvider.getConfig()));
            }
            if (tmpl.contains(Constants.TMPL_ATTR_PRESENT_SET)) {
                String setAttrPresentTmpl = null;
                if (Util.presentMaskRequired(attrUse, dataProvider.getConfig())) {
                    setAttrPresentTmpl = dataProvider.getConfig().getTemplateAttributePresentSet();
                    setAttrPresentTmpl = fillInTemplate(setAttrPresentTmpl, cppElementName, element, attrUse,
                            dataMethodName, listType, simpleTypeValiTmpl, dataProvider);
                } else {
                    setAttrPresentTmpl = "";
                }
                tmpl = tmpl.replace(Constants.TMPL_ATTR_PRESENT_SET, setAttrPresentTmpl);
            }
            if (tmpl.contains(Constants.TMPL_ATTR_PRESENT_CHECK)) {
                String checkAttrPresentTmpl = null;
                if (Util.presentMaskRequired(attrUse, dataProvider.getConfig())) {
                    checkAttrPresentTmpl = dataProvider.getConfig().getTemplateAttributePresentCheck();
                    checkAttrPresentTmpl = fillInTemplate(checkAttrPresentTmpl, cppElementName, element, attrUse,
                            dataMethodName, listType, simpleTypeValiTmpl, dataProvider);
                } else {
                    checkAttrPresentTmpl = "";
                }
                tmpl = tmpl.replace(Constants.TMPL_ATTR_PRESENT_CHECK, checkAttrPresentTmpl);
            }
            if (tmpl.contains(Constants.TMPL_ATTR_NOT_PRESENT_CHECK)) {
                String checkAttrNotPresentTmpl = null;
                if (Util.presentMaskRequired(attrUse, dataProvider.getConfig())) {
                    checkAttrNotPresentTmpl = dataProvider.getConfig().getTemplateAttributeNotPresentCheck();
                    checkAttrNotPresentTmpl = fillInTemplate(checkAttrNotPresentTmpl, cppElementName, element, attrUse,
                            dataMethodName, listType, simpleTypeValiTmpl, dataProvider);
                } else {
                    checkAttrNotPresentTmpl = "";
                }
                tmpl = tmpl.replace(Constants.TMPL_ATTR_NOT_PRESENT_CHECK, checkAttrNotPresentTmpl);
            }
        }

        if (element != null && cppElementName != null) {
            if (tmpl.contains(Constants.TMPL_ATTRIBUTE_STRUCT_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_ATTRIBUTE_STRUCT_NAME, Util.createAttributeStructName(
                        cppElementName, element, dataProvider.getConfig(), dataProvider.getCompleteElementUsage()));
            }
        }

        if (tmpl.contains(Constants.TMPL_ATTRIBUTE_STRUCT_SUFFIX)) {
            tmpl = tmpl.replace(Constants.TMPL_ATTRIBUTE_STRUCT_SUFFIX, dataProvider.getConfig()
                    .getAttributeStructSuffix());
        }

        if (tmpl.contains(Constants.TMPL_UNKNOWN_ATTRIBUTES_MEMBER_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_UNKNOWN_ATTRIBUTES_MEMBER_NAME, dataProvider.getConfig()
                    .getUnknownAttributesMemberName());
        }
        if (tmpl.contains(Constants.TMPL_UNKNOWN_ATTRIBUTES_MEMBER_TYPE)) {
            tmpl = tmpl.replace(Constants.TMPL_UNKNOWN_ATTRIBUTES_MEMBER_TYPE, dataProvider.getConfig()
                    .getUnknownAttributesMemberType());
        }
        if (tmpl.contains(Constants.TMPL_UNKNOWN_ATTRIBUTE_TYPE)) {
            tmpl = tmpl.replace(Constants.TMPL_UNKNOWN_ATTRIBUTE_TYPE, dataProvider.getConfig()
                    .getUnknownAttributeType());
        }

        if (tmpl.contains(Constants.TMPL_CLASS_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_CLASS_NAME, dataProvider.getConfig().getClassNamePublic());
        }
        if (tmpl.contains(Constants.TMPL_PRIVATE_CLASS_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_PRIVATE_CLASS_NAME, dataProvider.getConfig().getClassNamePrivate());
        }
        if (tmpl.contains(Constants.TMPL_MIMPL)) {
            tmpl = tmpl.replace(Constants.TMPL_MIMPL, dataProvider.getConfig().getPublicImplMember());
        }
        if (tmpl.contains(Constants.TMPL_TYPED_ATTRIBUTE_STRUCT_VARIABLE_NAME)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPED_ATTRIBUTE_STRUCT_VARIABLE_NAME, dataProvider.getConfig()
                    .getTypedAttributeDataVariableName());
        }

        if (dataMethodName != null) {
            if (tmpl.contains(Constants.TMPL_DATA_METHOD)) {
                tmpl = tmpl.replace(Constants.TMPL_DATA_METHOD, dataMethodName);
            }
        }

        if (tmpl.contains(Constants.TMPL_NEWLINE)) {
            tmpl = tmpl.replace(Constants.TMPL_NEWLINE, "\n");
        }
        if (tmpl.contains(Constants.TMPL_INDENT)) {
            tmpl = tmpl.replace(Constants.TMPL_INDENT, dataProvider.getConfig().getIndentation());
        }

        return tmpl;
    }

    /**
     * Fills in code templates related to type mapping.
     * 
     * @param tmpl
     *            Template to fill in.
     * @param cppElementName
     *            C++ name of element given template belongs to.
     * @param attrUse
     *            Attribute given template belongs to.
     * @param dataProvider
     *            Data provider.
     * @return Filled in template.
     */
    public static String fillInTypeMappingTemplate(String tmpl, String cppElementName, XSAttributeUse attrUse,
            IGenerationDataProvider dataProvider) {
        Config config = dataProvider.getConfig();

        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_ATTR_ATOMIC_XSD2CPP_RHS)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_ATTR_ATOMIC_XSD2CPP_RHS, config
                    .getTemplateTypeMappingDefaultAttrAtomicXsd2cppRhs());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_ATTR_LIST_XSD2CPP_RHS)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_ATTR_LIST_XSD2CPP_RHS, config
                    .getTemplateTypeMappingDefaultAttrListXsd2cppRhs());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_DATA_METHOD_IMPL)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_DATA_METHOD_IMPL, config
                    .getTemplateTypeMappingDefaultDataAtomicDataMethodImpl());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_POST_ATTR_ATOMIC_XSD2CPP)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_POST_ATTR_ATOMIC_XSD2CPP, config
                    .getTemplateTypeMappingDefaultPostAttrAtomicXsd2cpp());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_POST_DATA_ATOMIC_XSD2CPP)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_POST_DATA_ATOMIC_XSD2CPP, config
                    .getTemplateTypeMappingDefaultPostDataAtomicXsd2cpp());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_PRE_ATTR_ATOMIC_XSD2CPP)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_PRE_ATTR_ATOMIC_XSD2CPP, config
                    .getTemplateTypeMappingDefaultPreAttrAtomicXsd2cpp());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_PRE_DATA_ATOMIC_XSD2CPP)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_PRE_DATA_ATOMIC_XSD2CPP, config
                    .getTemplateTypeMappingDefaultPreDataAtomicXsd2cpp());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_UNION_DATA_ATOMIC_XSD2CPP_RHS)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_UNION_DATA_ATOMIC_XSD2CPP_RHS, config
                    .getTemplateTypeMappingDefaultUnionDataAtomicXsd2cppRhs());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_ATTR_ATOMIC_XSD2CPP)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_ATTR_ATOMIC_XSD2CPP, config
                    .getTemplateTypeMappingDefaultEnumSringAttrAtomicXsd2cpp());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_ATOMIC_XSD2CPP)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_ATOMIC_XSD2CPP, config
                    .getTemplateTypeMappingDefaultEnumSringDataAtomicXsd2cpp());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_LIST_DATAEND)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_LIST_DATAEND, config
                    .getTemplateTypeMappingDefaultEnumSringDataListDataend());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_LIST_XSD2CPP)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_ENUM_STRING_DATA_LIST_XSD2CPP, config
                    .getTemplateTypeMappingDefaultEnumSringDataListXsd2cpp());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_STRING_DATA_XSD2CPP)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_STRING_DATA_XSD2CPP, config
                    .getTemplateTypeMappingDefaultSringDataXsd2cpp());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_CONVERSION)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_CONVERSION, config
                    .getTemplateTypeMappingDefaultDataAtomicConversion());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_VALIDATE_END_FACET_PATTERN)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_VALIDATE_END_FACET_PATTERN, config
                    .getTemplateTypeMappingDefaultDataAtomicValidateEndFacetPattern());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_XSD2CPP_RHS)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_ATOMIC_XSD2CPP_RHS, config
                    .getTemplateTypeMappingDefaultDataAtomicXsd2cppRhs());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_LIST_XSD2CPP_LHS)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_LIST_XSD2CPP_LHS, config
                    .getTemplateTypeMappingDefaultDataListXsd2cppLhs());
        }
        if (tmpl.contains(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_LIST_XSD2CPP_VALIDATION_LHS)) {
            tmpl = tmpl.replace(Constants.TMPL_TYPE_MAP_DEFAULT_DATA_LIST_XSD2CPP_VALIDATION_LHS, config
                    .getTemplateTypeMappingDefaultDataListXsd2cppValidationLhs());
        }

        return tmpl;
    }

    /**
     * Fills in a C++ code template related to XSD union member types.
     * 
     * @param tmpl
     *            Code template to process.
     * @param unionType
     *            XSD union type given template belongs to.
     * @param memberType
     *            XSD type of union member given template belongs to.
     * @param memberNumber
     *            Position of given member in list of all union members.
     * @param dataProvider
     *            DataProvider.
     * 
     * @return Filled in code template.
     */
    public static String fillInUnionMemberTemplate(String tmpl, XSSimpleTypeDefinition unionType,
            XSSimpleTypeDefinition memberType, int memberNumber, IGenerationDataProvider dataProvider) {

        Config config = dataProvider.getConfig();
        CppEnumNameCreator cppUnionNameCreator = dataProvider.getEnumOrUnionNameCreator();
        Map<XSSimpleTypeDefinition, Map<XSSimpleTypeDefinition, StringPair>> unionMemberTypeMap = dataProvider
                .getUnionMemberTypeMap();

        int iterationCounter = 0;
        while (tmpl.contains(Constants.TEMPLATE_DELIMITER_UNION)) {
            iterationCounter++;
            if (iterationCounter > config.getMaxTemplateResolvingIterations()) {
                System.err.println("********************************************");
                System.err.println("Could not resolve template:");
                System.err.println(fillInTemplate(tmpl, null, null, null, null, null, null, dataProvider));
                System.err.println("********************************************");
                break;
            }

            tmpl = fillInUnionTemplate(tmpl, unionType, dataProvider);

            String cppMemberName = cppUnionNameCreator.createUnionMemberTypeName(memberType, unionType);
            Map<XSSimpleTypeDefinition, StringPair> map = unionMemberTypeMap.get(unionType);
            StringPair stringPair = map.get(memberType);
            if (tmpl.contains(Constants.TMPL_UNION_MEMBER_CPP_TYPE)) {
                String cppType = stringPair.str2;
                tmpl = tmpl.replace(Constants.TMPL_UNION_MEMBER_CPP_TYPE, cppType);
            }
            if (tmpl.contains(Constants.TMPL_UNION_MEMBER_TMP_VAR)) {
                tmpl = tmpl.replace(Constants.TMPL_UNION_MEMBER_TMP_VAR, "tmp" + memberNumber);
            }
            if (tmpl.contains(Constants.TMPL_UNION_MEMBER_TYPE_ENUM)) {
                tmpl = tmpl.replace(Constants.TMPL_UNION_MEMBER_TYPE_ENUM, cppMemberName);
            }
            if (tmpl.contains(Constants.TMPL_UNION_MEMBER_CONVERSION_FUNC_NAME)) {
                String cppConversion = null;
                if (Util.hasFacetEnum(memberType)) {
                    String toEnum = config.getTemplateUnionEnumMemberConversion();
                    String cppEnumTypeName = cppUnionNameCreator.createEnumTypeName(memberType, null);
                    cppConversion = fillInEnumTemplate(toEnum, cppEnumTypeName, memberType, null, 0, dataProvider);

                } else {
                    String xsdType = stringPair.str1;
                    cppConversion = config.getTypeMapping().get(xsdType).getUnionAtomicTypeConversion();
                }
                cppConversion = fillInTypeMappingTemplate(cppConversion, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_MEMBER_CONVERSION_FUNC_NAME, cppConversion);
            }
            if (tmpl.contains(Constants.TMPL_UNION_MEMBER_CONVERSION_FUNC_PARAS)) {
                String paras = config.getUnionMemberTypeConversionFunctionParameters();
                if (Util.hasFacetEnum(memberType)) {
                    paras += config.getTemplateUnionMemberTypeConversionFunctionParametersEnumAddon();
                    String cppEnumTypeName = cppUnionNameCreator.createEnumTypeName(memberType, null);
                    paras = fillInEnumTemplate(paras, cppEnumTypeName, memberType, null, 0, dataProvider);
                }
                tmpl = tmpl.replace(Constants.TMPL_UNION_MEMBER_CONVERSION_FUNC_PARAS, paras);
            }
            if (tmpl.contains(Constants.TMPL_UNION_ENUM_BASE_FUNC)) {
                String xsdType = stringPair.str1;
                String cppConversion = config.getTypeMapping().get(xsdType).getUnionEnumBaseTypeConversion();
                cppConversion = fillInTypeMappingTemplate(cppConversion, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_ENUM_BASE_FUNC, cppConversion);
            }
            if (tmpl.contains(Constants.TMPL_UNION_ENUM_BASE_TYPE)) {
                String xsdType = stringPair.str1;
                String enumBaseType = config.getTypeMapping().get(xsdType).getUnionEnumBaseType();
                enumBaseType = fillInTypeMappingTemplate(enumBaseType, null, null, dataProvider);
                tmpl = tmpl.replace(Constants.TMPL_UNION_ENUM_BASE_TYPE, enumBaseType);
            }

        }
        return tmpl;
    }

    /**
     * Fills in C++ code templates related to XSD unions.
     * 
     * @param tmpl
     *            Code template to fill in.
     * @param unionType
     *            XSD union type given template belongs to.
     * @param dataProvider
     *            DataProvider.
     * 
     * @return Filled in code template.
     */
    public static String fillInUnionTemplate(String tmpl, XSSimpleTypeDefinition unionType,
            IGenerationDataProvider dataProvider) {

        Config config = dataProvider.getConfig();
        CppEnumNameCreator cppUnionNameCreator = dataProvider.getEnumOrUnionNameCreator();

        int iterationCounter = 0;
        while (tmpl.contains(Constants.TEMPLATE_DELIMITER_UNION)) {
            iterationCounter++;
            if (iterationCounter > config.getMaxTemplateResolvingIterations()) {
                break;
            }

            String cppUnionName = cppUnionNameCreator.createUnionTypeName(unionType, null);
            if (tmpl.contains(Constants.TMPL_UNION_CPP_TYPE_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_UNION_CPP_TYPE_NAME, cppUnionName);
            }
            if (tmpl.contains(Constants.TMPL_UNION_TYPE_MEMBER_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_UNION_TYPE_MEMBER_NAME, config.getUnionTypeMemberName());
            }
            if (tmpl.contains(Constants.TMPL_UNION_DATA_MEMBER_NAME)) {
                tmpl = tmpl.replace(Constants.TMPL_UNION_DATA_MEMBER_NAME, config.getUnionDataMemberName());
            }
            if (tmpl.contains(Constants.TMPL_UNION_FUNC_TO_UNION)) {
                tmpl = tmpl.replace(Constants.TMPL_UNION_FUNC_TO_UNION, Util.createUnionFuncNameToUnion(cppUnionName,
                        config));
            }
            if (tmpl.contains(Constants.TMPL_UNION_FUNC_DATA_PREFIX)) {
                tmpl = tmpl.replace(Constants.TMPL_UNION_FUNC_DATA_PREFIX, Util.createUnionFuncNameToUnionPrefix(
                        cppUnionName, config));
            }

            if (tmpl.contains(Constants.TMPL_UNION_TO_UNION_PER_MEMBER)) {
                String allMembersCode = new String();
                List<XSSimpleTypeDefinition> memberTypes = Util.objectListToList(unionType.getMemberTypes());
                for (int i = 0; i < memberTypes.size(); i++) {
                    String perMemberTmpl = config.getTemplateUnionFuncToUnionPerMember();
                    XSSimpleTypeDefinition memberType = memberTypes.get(i);
                    perMemberTmpl = fillInUnionMemberTemplate(perMemberTmpl, unionType, memberType, i, dataProvider);
                    allMembersCode += perMemberTmpl;
                }
                tmpl = tmpl.replace(Constants.TMPL_UNION_TO_UNION_PER_MEMBER, allMembersCode);
            }
        }
        return tmpl;
    }

    /**
     * Prepares a simple type validation code template.
     * 
     * Calls Complex validation method for simple type validation. Needed
     * because a complex type validation code template is reused. Call
     * {@link #fillInSimpleValidationTemplate(String, XSSimpleTypeDefinition, Config, Map)}
     * first for recursive replacement.
     * 
     * @param tmpl
     *            Code template to process.
     * @param simpleType
     *            XSD type given template belongs to.
     * @param cppElementName
     *            C++ name of element given template belongs to.
     * @param element
     *            XSD element given template belongs to.
     * @param dataProvider
     *            DataProvider.
     * 
     * @return Prepared code template.
     */
    public static String prepareSimpleTypeValidationTemplate(String tmpl, XSSimpleTypeDefinition simpleType,
            String cppElementName, XSElementDeclaration element, IGenerationDataProvider dataProvider) {

        String cppValiStructName = dataProvider.getXsType2validationDataStructName().get(simpleType);
        tmpl = fillInSimpleValidationTemplate(tmpl, simpleType, dataProvider.getConfig(), dataProvider
                .getXsSimpleType2validationFunctionName());
        if (cppValiStructName != null) {
            tmpl = fillInComplexValidationTemplate(tmpl, cppElementName, cppValiStructName, null, element, null,
                    dataProvider);
        }
        tmpl = fillInSimpleValidationTemplate(tmpl, simpleType, dataProvider.getConfig(), dataProvider
                .getXsSimpleType2validationFunctionName());
        if (cppValiStructName != null) {
            tmpl = fillInComplexValidationTemplate(tmpl, cppElementName, cppValiStructName, null, element, null,
                    dataProvider);
        } else {
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_GET_VALIDATION_DATA)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_GET_VALIDATION_DATA, dataProvider.getConfig()
                        .getTemplateSimpleValidationGetValidationDataNoValidation());
            }
            if (tmpl.contains(Constants.TMPL_COMPLEX_VALI_DELETE_VALIDATION_DATA)) {
                tmpl = tmpl.replace(Constants.TMPL_COMPLEX_VALI_DELETE_VALIDATION_DATA, dataProvider.getConfig()
                        .getTemplateSimpleValidationDeleteValidationDataNoValidation());
            }
        }
        return tmpl;
    }
}
