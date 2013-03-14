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
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

/**
 * Specialized node which allows querying of nodes by name.
 * 
 */
public class StateMachineRootNode extends StateMachineNode {

    /** Contains all nodes of this StateMachine. */
    private SortedMap<String, List<StateMachineNode>> nodes = new TreeMap<String, List<StateMachineNode>>();

    /**
     * Constructor.
     */
    public StateMachineRootNode(String name) {
        super(name);
        registerNode(name, this);
    }

    /**
     * Finds nodes with given name in this state machine.
     * 
     * @param name
     *            Name to find nodes with.
     * @return Nodes with given name.
     */
    public List<StateMachineNode> findNodes(String name) {
        return nodes.get(name);
    }

    /**
     * @return All node names in this state machine.
     */
    protected SortedSet<String> getNodeNames() {
        SortedSet<String> sortedNames = new TreeSet<String>();
        sortedNames.addAll(nodes.keySet());
        return sortedNames;
    }

    /**
     * Registers a new node. To be called when a node is added to this state
     * machine.
     * 
     * @param name
     *            Name of the node.
     * @param node
     *            The node itself.
     */
    protected void registerNode(String name, StateMachineNode node) {
        List<StateMachineNode> nodesList = nodes.get(name);
        if (nodesList == null) {
            nodes.put(name, new ArrayList<StateMachineNode>());
            nodesList = nodes.get(name);
        }
        nodesList.add(node);
    }
}
