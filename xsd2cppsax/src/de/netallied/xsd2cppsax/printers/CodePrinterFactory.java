package de.netallied.xsd2cppsax.printers;

import java.util.ArrayList;
import java.util.List;

import de.netallied.xsd2cppsax.Config;
import de.netallied.xsd2cppsax.IGenerationDataProvider;

/**
 * Creates {@link ICodePrinter}s.
 * 
 */
public class CodePrinterFactory {

    /**
     * Creates {@link ICodePrinter}s with respect to config.
     * 
     * @param dataProvider
     *            {@link IGenerationDataProvider} to be used by
     *            {@link ICodePrinter}s.
     * @return List of {@link ICodePrinter}s.
     */
    public static List<ICodePrinter> createCodePrinters(IGenerationDataProvider dataProvider) {
        Config config = dataProvider.getConfig();
        List<ICodePrinter> printers = new ArrayList<ICodePrinter>();
        if (config.getGenerateExampleParser()) {
            printers.add(new ExampleParserPrinter(dataProvider));
        }
        if (config.getGenerateFprintfParser()) {
            printers.add(new FPrintfParserPrinter(dataProvider));
        }
        if (config.getGenerateCoherencyTestParser()) {
            printers.add(new SaxCoherencyTest14ParserPrinter(dataProvider));
        }
        return printers;
    }
}
