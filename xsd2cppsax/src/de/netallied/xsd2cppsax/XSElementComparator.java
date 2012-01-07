package de.netallied.xsd2cppsax;

import java.util.Comparator;
import java.util.SortedMap;

import org.apache.xerces.xs.XSElementDeclaration;

/**
 * Allows comparison of {@link XSElementDeclaration}s. That way they can be used
 * as keys in a {@link SortedMap}.
 * 
 */
public class XSElementComparator implements Comparator<XSElementDeclaration> {

    /**
     * {@inheritDoc}
     * 
     * @see java.util.Comparator#compare(java.lang.Object, java.lang.Object)
     */
    public int compare(XSElementDeclaration o1, XSElementDeclaration o2) {
        if (o1.equals(o2))
            return 0;

        String str01 = o1.toString();
        String str02 = o2.toString();
        return str01.compareTo(str02);
    }

}
