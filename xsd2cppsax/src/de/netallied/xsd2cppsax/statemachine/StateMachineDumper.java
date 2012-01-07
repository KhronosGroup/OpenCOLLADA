package de.netallied.xsd2cppsax.statemachine;

import java.util.List;

/**
 * Dumps out a state machine to std out. For debugging purposes.
 * 
 */
public class StateMachineDumper {

    public void dump(StateMachineRootNode rootNode) {
        System.out.println("****************************************");
        for (String nodeName : rootNode.getNodeNames()) {
            List<StateMachineNode> nodes = rootNode.findNodes(nodeName);
            System.out.println("node: " + nodeName);
            for (StateMachineNode node : nodes) {
                System.out.println("  following: ");
                for (StateMachineNode follow : node.getFollowingStates()) {
                    System.out.println("    " + follow.getName());
                }
                System.out.println("  prev:");
                for (StateMachineNode prev : node.getPrecedingStates()) {
                    System.out.println("    " + prev.getName());
                }
            }
        }
        System.out.println("****************************************");
    }
}
