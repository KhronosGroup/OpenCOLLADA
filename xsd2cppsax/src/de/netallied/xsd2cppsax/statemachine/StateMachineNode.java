package de.netallied.xsd2cppsax.statemachine;

import java.util.ArrayList;
import java.util.List;

import de.netallied.xsd2cppsax.Constants;
import de.netallied.xsd2cppsax.Util;

/**
 * Node of a state machine. State machines are necessary for complex type
 * validation with nested model groups.
 * 
 */
public class StateMachineNode {

    /** Following states of this node. */
    private List<StateMachineNode> followingStates = new ArrayList<StateMachineNode>();

    /** Node name. */
    private String name;

    /** Preceding states of this node. */
    private List<StateMachineNode> precedingStates = new ArrayList<StateMachineNode>();

    /** Node id. To be used in C++ code. */
    private String stateID;

    /**
     * Constructor.
     */
    public StateMachineNode(String name) {
        this.name = name;
        stateID = createID(name);
    }

    /**
     * Adds a following state.
     * 
     * @param node
     *            State to add.
     */
    protected void addFollowing(StateMachineNode node) {
        this.getFollowingStates().add(node);
        node.getPrecedingStates().add(this);
    }

    /**
     * Creates node id from it's name. The id can be used in C++ code.
     * 
     * @param name
     *            Node name.
     * @return Node id.
     */
    protected String createID(String name) {
        if (name == Constants.STATE_MACHINE_ROOT_NODE_NAME) {
            return Constants.STATE_MACHINE_ROOT_CPP_CONSTANT;
        } else if (name == Constants.STATE_MACHINE_END_NODE_NAME) {
            return Constants.STATE_MACHINE_END_CPP_CONSTANT;
        }
        return Util.createElementNameHashIdentifier(name);
    }

    /**
     * @return Following states.
     */
    public List<StateMachineNode> getFollowingStates() {
        return followingStates;
    }

    /**
     * @return Node name.
     */
    public String getName() {
        return name;
    }

    /**
     * @return Preceding states.
     */
    public List<StateMachineNode> getPrecedingStates() {
        return precedingStates;
    }

    /**
     * @return Node id. To be used in C++ code.
     */
    public String getStateID() {
        return stateID;
    }

    /**
     * {@inheritDoc}
     * 
     * @see java.lang.Object#toString()
     */
    @Override
    public String toString() {
        return "\"" + name + "\"";
    }
}
