            
Import('env')

libName = 'OpenCOLLADASaxFrameworkLoader'


srcDirs = [ 'src/',
            'src/generated14/',
            'src/generated15/']

variantDir = env['objDir']  + env['configurationBaseName'] + env['xmlParserConfName'] + env['validationConfName'] + '/'
outputDir =  env['libDir']  + env['configurationBaseName'] + env['xmlParserConfName'] + env['validationConfName'] + '/'
targetPath = outputDir + libName


incDirs = [ 'include',
            'include/generated14',
            'include/generated15',
            '../COLLADABaseUtils/include',
            '../GeneratedSaxParser/include',
            '../COLLADAFramework/include',
            '../Externals/LibXML/include',
            '../Externals/MathMLSolver/include',
            '../Externals/MathMLSolver/include/AST']

if not env['PCRENATIVE']:
    incDirs += ['../Externals/pcre/include']

src = []
for srcDir in srcDirs:
    src += [ variantDir + str(p) for p in  Glob(srcDir + '*.cpp')]   
    VariantDir(variant_dir=variantDir + srcDir, src_dir=srcDir, duplicate=False)

if (env['XMLPARSER'] == 'expat') or (env['XMLPARSER'] == 'expatnative'):
    env['CPPFLAGS'] += ' -DGENERATEDSAXPARSER_XMLPARSER_EXPAT'
else:
    env['CPPFLAGS'] += ' -DGENERATEDSAXPARSER_XMLPARSER_LIBXML'

if not env['NOVALIDATION']:
    env['CPPFLAGS'] += ' -DGENERATEDSAXPARSER_VALIDATION'


if env['SHAREDLIB']:
    SharedLibrary(target=targetPath, source=src, CPPPATH=incDirs, CCFLAGS=env['CPPFLAGS'])
else:
    StaticLibrary(target=targetPath, source=src, CPPPATH=incDirs, CCFLAGS=env['CPPFLAGS'])
