**********************
xsd2cppsax Anleitung
**********************

1. Aufruf des Generators
************************
xsd2cppsax ist ein Code Generator, der aus einem XSD einen C++ SAX Parser generiert. Um die
Code Generierung zu starten kann folgende Kommandozeile verwendet werden:

java -cp xsd2cppsax.jar;xercesImpl.jar de.netallied.xsd2cppsax.Main -c < Pfad zur Config Datei >

Es wird Java mindestens in Version 5 benötigt.

Da der generierte Code Reguläre Ausdrücke des XSDs mit vorkompilierten pcre Ausdrücken
validiert, muss sich pcre_compiler.exe im Working Directory befinden. 

Neben -c stehen noch zwei optionale Kommandozeilen Parameter zur Verfügung. Diese überschreiben
Optionen aus der Config Datei:
-i <input XSD>
-r <root element name>
Mittels dieser optionalen Parameter kann eine Config Datei mit mehreren XSDs verwendet werden.
Während des generierens wird auf optionale Attribute ohne Default-Wert hingewiesen. Bei späterer
integration des generierten parsers in eine Anwendung muss beachtet werden, dass diese Attribute
einen undefinierten Wert haben können.



2. Über den generierten Code
****************************
Grundsätzlich werden zwei Klassen generiert: PublicParser und PrivateParser.
Der PrivateParser wird intern Verwendet. Er dient dazu die Text Daten des Eingabe 
Dokuments in binäre Daten umzuwandeln (z.B. float oder URI). Außerdem ist er in
der Lage, das Eingabe Dokument zu validieren. Die Validierung ist zur Compile-Zeit
und zur Laufzeit abschaltbar. Nachdem der PrivateParser die Text Daten geparst hat
übergibt er sie an die Methoden des PublicParsers.

Der PublicParser ist dazu gedacht, von ihm abzuleiten. Für jedes Element des XSDs
stellt er zwei oder drei Methoden zur Verfügung. Die beiden die immer Verfügbar sind,
sind eine "begin" und eine "end" Methode für jedes Element. Die dritte Methode beginnt
mit "data". Durch sie werden die geparsten XML Text Daten an den Implementierer 
übergeben. Da nicht jedes Element Text Daten haben kann, ist diese Methode auch nicht
für jedes Element verfügbar. Die "begin", "end" und "data" Methoden folgen dem SAX
Prinzip. Die Attribute eines Elements werden der "begin" Methode mit übergeben. Für
die Attribute werden C++ structs generiert. Falls erforderlich enthalten diese structs
Bit-Felder um abzuprüfen ob ein Attribut gesetzt ist oder nicht.

Für den XSD Typ "anyURI" wird eine C++ URI Klasse verwendet. Diese stammt aus dem BaseUtils
Paket des OpenCOLLADA Projekts.

Für XSD enums und unions werden auch C++ enums und unions generiert. Diese werden in
den Attribut structs und bei den "data" Methoden verwendet.

Eventuell auftretende Validierungs-Fehler werden an einen ErrorHandler übergeben. Dieser
sollte vom Anwendungs-Entwickler implementiert werden. Er kann entscheiden ob bei einem
Fehler abgebrochen wird oder nicht. Es wird eine Beispiel Implementierung mit geliefert,
welche alle Fehler über die Standart-Ausgabe ausgibt und nie abbricht.

Dieser CoutErrorHandler befindet sich im Paket "GeneratedSaxParser" des OpenCOLLADA Projekts.
Dort befinden sich noch weitere Klassen die vom generierten Code verwendet werden. Dieses
Prjekt bietet die Möglichkeit zwei verschiedene XML Biblitheken als Basis für den
generierten Parser zu verwenden. Dies sind libxml und expat. Mittels Präpozessor
Flag kann zwischen ihnen gewählt werden:
- GENERATEDSAXPARSER_XMLPARSER_LIBXML
- GENERATEDSAXPARSER_XMLPARSER_EXPAT
Ein weiteres Präpozessor flag dient dazu, die Validierung zur Compile-Zeit einzuschalten:
- GENERATEDSAXPARSER_VALIDATION

Optional können zwei Implementierungen des PublicParsers generiert werden. Die eine,
ExampleParser, tut nichts. Sie dient als Beispiel wie ein eigener Parser implementiert
werden kann. Die andere, fprintf parser, schreibt die geparste Datei wieder in eine
andere Datei (mittles der C funktion fprinf). Sie kann für Performance Messungen oder 
auch als Implementierungs Vorlage dienen.

Experimentell ist auch eine dritte PublicParser Implementierung verfügbar: CoherencyTestParser.
Er dient der Überprüfung von COLLADA Dokumenten, ist also spezifisch für ein XSD. Da
er experimentell ist und kaum features bietet, wird von einer Generierung abgeraten.

Ein Großteil des generierten Codes wird durch Code Templates definiert. Diese Code 
Templates befinden sich in einer Datei welche von der Config Datei referenziert 
wird. Da Änderungen hieran sehr leicht zu unkompilierbarem Code führen können, wird 
empfohlen, die mitgelieferte Code Templates Datei unverändert zu verwenden.

Um eine hohe Performance zu erreichen wird innerhalb des PrivateParsers ein spezielles 
Memory Management verwendet. Wie anfangs beschrieben, parst der PrivateParser die
Text Daten des Dokuments. Um die binären Daten ablegen zu können ist Speicher erforderlich.
Da die C/C++ default Speicher Verwaltung mit einer Vielzahl an spezial Fällen zurecht
kommen muss, und evtl. das Betriebssystem sogar in den Kernel-Mode wechseln muss, kann
diese sehr langsam sein. Das Memory Management des PrivateParsers ist in der C++ Klasse
GeneratedSaxParser::StackMemoryManager gekapselt. Dieser Manager alloziert zu beginn
eine bestimmte Menge Speicher (per default 1 MB). Bei Bedarf wird in diesem Speicher
ein Objekt angelegt. Die größe des Objekts wird am seinem Ende mit abgelegt. Diese
Größenangabe dient später dem korrekten freigeben des Objekts. Da der Manager nach dem
Stack Prinzip arbeitet, werden neuen Objekte immer am Ende des belegten Speichers angelegt
und es kann immer nur das letzte Objekt gelöscht werden. Das Löschen ist enorm schnell, 
da nur ein paar interne Status Variablen des Managers geändert werden müssen. Da wärend
des Parsens nicht immer bekannt ist, wieviel Speicher benötigt wird, bietet der Manager 
die Möglichkeit, dass letzte Objekt auf dem Stack zu vergrößern. Der Speicher des Managers
wird, anders als bei C++ new, nicht initialisiert, weshalb er sich nicht für C++-Objekte
eignet (aber für pointer auf solche).

Ein weiteres Detail um die Performance zu steigern liegt im parsen von Gleitkomma Zahlen.
Anstatt C Funktionen wie atof() oder scanf() zu verwenden, verfügt der generierte Parser
über eine eigene Implementierung (GeneratedSaxParser::Utils::toFloatingPoint).

Während eines SAX-Parsing-Vorgangs müssen üblicherweise viele Strings verglichen werden
(die Element Namen) um die richtigen Funktionen aufzurufen. Um dies zu vermeiden setzt
der generierte Parser auf String Hashes. Damit wird die Performance nocheinmal gesteigert.



3. Konfigurations Möglichkeiten
*******************************
In der angesprochenen Config Datei lassen sich eine Vielzahl von Optionen festlegen.
Es wird empfohlen die mitgelieferte Beispiel Datei als Vorlage zu nehmen.
Hier Eine Auswahl der Optionen:
- Ausgabe Pfade für die generierten Dateien. Die Verzeichnisse müssen bereits existieren.
    outputHeaderFileNamePublic
    outputHeaderFileNamePrivate
    outputSourceFileNamePrivate
    outputExampleHeaderFileName
    outputExampleSourceFileName
    outputFPrintfHeaderFileName
    outputFPrintfSourceFileName
- Eingabe XSD
    inputFile
- Das Root Element des Eingabe XSDs
    rootElementName
- Klassennamen und Namespace des generierten Parsers
    namespace
    classNamePrivate
    classNamePublic
- Dateien die im generierten Code includiert werden
    includePrecompiledHeader
    includeFilesForEnumsHeader
    includeFilesForEnumsSource 
    includeFilesForImpl
    includeFilesForPrivateHeader
- Ein Header (z.B. mit Lizenz/Copyright informationen) für den generierten Code
    outFileHeader
- Ob XSD float und double in C++ als float oder double verwendet werden sollen
  Damit kann der Anwender selbst zwischen Geschwindigkeit und Genauigkeit wählen
    treatXsFloatAsCppFloat
    treatXsDoubleAsCppDouble
- Elemente die unabhängig vom Rest eines Dokuments geparst werden sollen
  (Bei der OpenCOLLADA Bibliothek wird das für die "Parser-Flags" verwendet)
    specialFunctionMapsStartElementNamesAllLevels
    specialFunctionMapsStartElementNamesOneLevel
- XSD Element Namen welche im Zusammenhang mit Complex Type Validation umbenannt werden müssen,
  da sie in C++ nicht erlaubt sind
    cppStructMemberNameMapping
- Generierte C++ Typnamen welche umbenannt werden sollen
  (z.B. für Anonyme Enums des XSDs)
    userTypeNameMapping
- XML Namespaces welche abgekürzt werden sollen (um die Lesbarkeit zu erhöhen)
    xsNamespaceMapping
- Ob eine Beispiel Parser Implementierung generiert werden soll
    generateExampleParser
- Ob der fprintf Parser generiert werden soll
  (dieser schreibt die geparste Datei sofort wieder in eine Datei)
    generateFprintfParser
- Klassennamen und Namespace von Beispiel- und fprintf-Parser
    exampleClassName
    exampleNamespace
    fPrintfParserClassName
    fPrintfParserNamespace
- Es stehen noch weitere Optionen zur Verfügung, die z.B. Typen und Namen 
  von Variablen im generierten Code ändern oder zu generierten Typ-Namen 
  oder Methoden suffixe/prefixe hinzufügen.
  Änderungen hieran können dazu führen, dass der generierte Code nicht mehr kompilierbar ist.
    convenienceDataMethodLengthParameterName
    simpleValidationFunctionLengthParameterType
    cppEnumTypePrefix
    attributeStructSuffix
    ...
