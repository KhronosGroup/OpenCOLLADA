/**
 *   Copyright &copy; 2008-2012 NetAllied Systems GmbH, Ravensburg, Germany. 
 *       
 *   Licensed under the MIT Open Source License, 
 *   for details please see LICENSE file or the website
 *   http://www.opensource.org/licenses/mit-license.php
*/
package de.netallied.xsd2cppsax.statemachine;

import java.util.ArrayList;
import java.util.List;

import org.apache.xerces.xs.XSComplexTypeDefinition;
import org.apache.xerces.xs.XSElementDeclaration;
import org.apache.xerces.xs.XSModelGroup;
import org.apache.xerces.xs.XSParticle;
import org.apache.xerces.xs.XSTypeDefinition;

import de.netallied.xsd2cppsax.Constants;

/**
 * Builds a state machine from a XSD complex type.
 * 
 */
public class StateMachineBuilder {

    /**
     * Small helper class to handle model groups with maxOccurs=unbounded.
     * <p>
     * e.g.
     * 
     * <pre>
     * &lt;sequence&gt;
     *      &lt;dog&gt;
     *      &lt;choice minOccurs=&quot;0&quot; maxOccurs=&quot;unbounded&quot;&gt;
     *          &lt;cat&gt;
     *          &lt;sequence&gt;
     *              &lt;black&gt;
     *              &lt;white&gt;
     *          &lt;/sequence&gt;
     *      &lt;/choice&gt;
     *      &lt;mouse&gt;
     * &lt;/sequence&gt;
     * </pre>
     * 
     * We need links from
     * <ul>
     * <li>cat to cat</li>
     * <li>cat to black</li>
     * <li>white to cat</li>
     * <li>white to black</li>
     * </ul>
     * This class' purpose is to return black and white from the above example.
     * black would be included in {@link #beginStates} and white in
     * {@link #endStates}.
     * </p>
     * 
         */
    protected static class ListPair {
        protected List<StateMachineNode> beginStates;

        protected List<StateMachineNode> endStates;

        protected ListPair() {
            beginStates = new ArrayList<StateMachineNode>();
            endStates = new ArrayList<StateMachineNode>();
        }
    }

    /**
     * Starts building of a state machine.
     * 
     * @param type
     *            XSD type to build state machine for.
     * @return State machine or null.
     */
    public StateMachineRootNode build(XSComplexTypeDefinition type) {
        if (type != null && type.getParticle() != null) {
            return build(type.getParticle());
        } else if (type != null && type.getBaseType() != null) {
            return build(type.getBaseType());
        }
        return null;
    }

    /**
     * Does real state machine building. To be called after types have been
     * checked and may be called for base types.
     * 
     * @param particle
     *            XSParticle to build state machine for.
     * @return State machine or null.
     */
    protected StateMachineRootNode build(XSParticle particle) {
        if (particle.getTerm() instanceof XSModelGroup) {
            XSModelGroup modelGroup = (XSModelGroup) particle.getTerm();
            boolean foundNestedModelGroup = false;
            for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
                XSParticle subParticle = (XSParticle) modelGroup.getParticles().item(i);
                if (subParticle.getTerm() instanceof XSModelGroup) {
                    foundNestedModelGroup = true;
                    break;
                }
            }
            if (!foundNestedModelGroup) {
                return null;
            }

            StateMachineRootNode rootNode = new StateMachineRootNode(Constants.STATE_MACHINE_ROOT_NODE_NAME);
            List<StateMachineNode> tmpList = new ArrayList<StateMachineNode>();
            tmpList.add(rootNode);
            tmpList = handleModelGroup(modelGroup, tmpList, rootNode, particle).endStates;
            StateMachineNode endNode = new StateMachineNode(Constants.STATE_MACHINE_END_NODE_NAME);
            rootNode.registerNode(endNode.getName(), endNode);
            for (StateMachineNode node : tmpList) {
                node.addFollowing(endNode);
            }
            return rootNode;
        }
        return null;
    }

    /**
     * Convenience method allowing to pass any types.
     */
    public StateMachineRootNode build(XSTypeDefinition type) {
        if (type instanceof XSComplexTypeDefinition) {
            return build((XSComplexTypeDefinition) type);
        }
        return null;
    }

    /**
     * Recursive function to add elements of model group to existing state
     * machine.
     * 
     * @param modelGroup
     *            Model group to handle.
     * @param previousNodes
     *            Existing state machine.
     * @param rootNode
     *            Root node of current state machine. Used to register nodes.
     * @param modelGroupParticle
     *            Particle of given model group. Needed for min/maxOccurs of
     *            whole model group.
     * @return Nodes which need following states.
     */
    protected ListPair handleModelGroup(XSModelGroup modelGroup, List<StateMachineNode> previousNodes,
            StateMachineRootNode rootNode, XSParticle modelGroupParticle) {

        if (modelGroupParticle.getTerm() != modelGroup) {
            throw new IllegalArgumentException("given model group and particle don't match.");
        }

        ListPair returnLists = new ListPair();
        List<StateMachineNode> originalPreviousNodes = new ArrayList<StateMachineNode>();
        originalPreviousNodes.addAll(previousNodes);

        switch (modelGroup.getCompositor()) {

        case XSModelGroup.COMPOSITOR_SEQUENCE:
            for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
                XSParticle particle = (XSParticle) modelGroup.getParticles().item(i);

                if (particle.getTerm() instanceof XSElementDeclaration) {
                    StateMachineNode newNode = new StateMachineNode(particle.getTerm().getName());
                    rootNode.registerNode(newNode.getName(), newNode);

                    if (particle.getMaxOccursUnbounded()) {
                        newNode.addFollowing(newNode);
                    }

                    List<StateMachineNode> tmp = new ArrayList<StateMachineNode>();
                    for (StateMachineNode prevNode : previousNodes) {
                        prevNode.addFollowing(newNode);

                        if (particle.getMinOccurs() == 0) {
                            tmp.add(prevNode);
                        }
                    }
                    previousNodes = tmp;
                    previousNodes.add(newNode);

                    if (i == 0) {
                        returnLists.beginStates.add(newNode);
                    }

                } else if (particle.getTerm() instanceof XSModelGroup) {
                    ListPair listPair = handleModelGroup((XSModelGroup) particle.getTerm(), previousNodes, rootNode,
                            particle);
                    previousNodes = listPair.endStates;

                    if (i == 0) {
                        returnLists.beginStates.addAll(listPair.beginStates);
                    }
                }

            }
            returnLists.endStates = previousNodes;
            break;

        case XSModelGroup.COMPOSITOR_CHOICE:
            for (int i = 0; i < modelGroup.getParticles().getLength(); i++) {
                XSParticle particle = (XSParticle) modelGroup.getParticles().item(i);

                if (particle.getTerm() instanceof XSElementDeclaration) {
                    StateMachineNode newNode = new StateMachineNode(particle.getTerm().getName());
                    rootNode.registerNode(newNode.getName(), newNode);
                    returnLists.endStates.add(newNode);
                    returnLists.beginStates.add(newNode);

                    if (particle.getMinOccurs() == 0) {
                        for (StateMachineNode prevNode : previousNodes) {
                            if (!returnLists.endStates.contains(prevNode)) {
                                returnLists.endStates.add(prevNode);
                            }
                        }
                    }
                    if (particle.getMaxOccursUnbounded()) {
                        newNode.addFollowing(newNode);
                    }

                    for (StateMachineNode prevNode : previousNodes) {
                        prevNode.addFollowing(newNode);
                    }

                } else if (particle.getTerm() instanceof XSModelGroup) {
                    ListPair listPair = handleModelGroup((XSModelGroup) particle.getTerm(), previousNodes, rootNode,
                            particle);
                    returnLists.endStates.addAll(listPair.endStates);
                    returnLists.beginStates.addAll(listPair.beginStates);
                }
            }

            break;

        }

        if (modelGroupParticle.getMaxOccursUnbounded()) {
            for (StateMachineNode endNode : returnLists.endStates) {
                for (StateMachineNode beginNode : returnLists.beginStates) {
                    endNode.addFollowing(beginNode);
                }
            }
        }
        if (modelGroupParticle.getMinOccurs() == 0) {
            for (StateMachineNode prevNode : originalPreviousNodes) {
                if (!returnLists.endStates.contains(prevNode)) {
                    returnLists.endStates.add(prevNode);
                }
            }
        }

        return returnLists;
    }
}
