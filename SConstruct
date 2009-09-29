debug = True
expat = True

builddir = 'scons-build'

srcdir = ['COLLADABaseUtils/src',
		  'COLLADABaseUtils/src/Math',
		  'COLLADAStreamWriter/src',
		  'COLLADAFramework/src',
		  'COLLADASaxFrameworkLoader/src',
		  'COLLADASaxFrameworkLoader/src/generated14',
		  'COLLADASaxFrameworkLoader/src/generated15',
		  'GeneratedSaxParser/src',
		  'Externals/MathMLSolver/src',
		  'Externals/MathMLSolver/src/AST',
		  'Externals/UTF/src']

incdir = ['COLLADABaseUtils/include',
		  'COLLADAStreamWriter/include',
		  'COLLADAFramework/include',
		  'COLLADASaxFrameworkLoader/include',
		  'COLLADASaxFrameworkLoader/include/generated14',
		  'COLLADASaxFrameworkLoader/include/generated15',
		  'GeneratedSaxParser/include',
		  'Externals/MathMLSolver/include',
		  'Externals/MathMLSolver/include/AST',
		  'Externals/UTF/include']

src = []
for d in srcdir:
	src += [builddir + '/' + str(p) for p in Glob(d + '/*.cpp') + Glob(d + '/*.c')]
	BuildDir(build_dir=builddir + '/' + d, src_dir=d, duplicate=False)

excl = ['COLLADASWSurface.cpp', 'MathMLASTFactory.cpp', 'GeneratedSaxParserLibxmlSaxParser.cpp' if expat else 'GeneratedSaxParserExpatSaxParser.cpp']
for f in src:
	for e in excl:
		if f.endswith(e):
			src.remove(f)

ccflags = ['-DGENERATEDSAXPARSER_XMLPARSER_EXPAT' if expat else '-DGENERATEDSAXPARSER_XMLPARSER_LIBXML', '-fsigned-char']

if debug:
	ccflags += ['-O0', '-g3', '-ggdb3', '-fno-inline']

Library(target='OpenCollada', source=src, CPPPATH=incdir, CCFLAGS=ccflags)
