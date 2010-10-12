import platform   #Requiered to detect the current plattform


Decider('MD5-timestamp')


# define the variables the user can set on the command line
vars = Variables('custom.py')
vars.Add(BoolVariable('RELEASE', 'Set to build for release', 0))
vars.Add(BoolVariable('PG', 'Set to build with -pg set for gcc for profiling', 0))
vars.Add(BoolVariable('SHAREDLIB', 'Set to build shared libraries instead of static ones (untested).', 0))
vars.Add(EnumVariable('LIBDIRNAME', 'The name of the systems library directory, for linux use', 'lib/', allowed_values=('lib/', 'lib64/') ))
vars.Add(BoolVariable('PCRENATIVE', 
"""Set to build using the systems native pcre lib instead of the delivered lib. Uses same configuration dir for both configurations.
""", 1))
vars.Add(EnumVariable('XMLPARSER',
"""Selects the xml parser to be used
    libxml: Use libXML contained in OpenCOLLADA external sources
    expat: Use expat contained in OpenCOLLADA external sources
    libxmlNative: Use libXML deliverd with your OS. libXML and the corresponding development files need to be installed
    expatNative: Use expat deliverd with your OS. expat and the corresponding development files need to be installed

"""
, 'libxmlnative', allowed_values=('libxml', 'expat', 'libxmlnative', 'expatnative'), ignorecase=2))
vars.Add(BoolVariable('NOVALIDATION', 'Set to disable shema validation in sax frame work loader', 0))

env=Environment( variables=vars )
Help(vars.GenerateHelpText(env))

if env['RELEASE']:
    configurationName = 'release'
    env['CPPFLAGS'] = ' -O2 -DNDEBUG'
else:
    configurationName = 'debug'
    env['CPPFLAGS'] = ' -O0 -g3 -ggdb3 -fno-inline'

if env['PG']:
    configurationName += 'Pg'
    env['CPPFLAGS'] += ' -pg'

env['platformDir'] = env['PLATFORM'] + '/'
env['architectureDir'] = platform.machine() + '/'
env['configurationBaseName'] = env['platformDir'] + env['architectureDir'] + configurationName

if (env['XMLPARSER'] == 'expat') or (env['XMLPARSER'] == 'expatnative'):
    env['xmlParserConfName'] = 'expat'
else:
    env['xmlParserConfName'] = 'libxml'

if env['NOVALIDATION']:
    env['validationConfName'] = 'Novalidation'
else:
    env['validationConfName'] = ''

env['objDir'] = 'obj/'
env['libDir'] = env['LIBDIRNAME']
env['binDir'] = 'bin/'


SConscript(['common/libftoa/SConscript'], exports = 'env')
SConscript(['common/libBuffer/SConscript'], exports = 'env')
SConscript(['COLLADABaseUtils/SConscript'], exports = 'env')
SConscript(['Externals/MathMLSolver/SConscript'], exports = 'env')
SConscript(['Externals/UTF/SConscript'], exports = 'env')
if not env['PCRENATIVE']:
    SConscript(['Externals/pcre/SConscript'], exports = 'env')


if env['XMLPARSER'] == 'expat':
    SConscript(['Externals/expat/SConscript'], exports = 'env')
elif env['XMLPARSER'] == 'libxml':
    SConscript(['Externals/LibXML/SConscript'], exports = 'env')

SConscript(['COLLADAFramework/SConscript'], exports = 'env')

SConscript(['GeneratedSaxParser/SConscript'], exports = 'env')
SConscript(['COLLADASaxFrameworkLoader/SConscript'], exports = 'env')
SConscript(['COLLADAStreamWriter/SConscript'], exports = 'env')

SConscript(['COLLADAValidator/SConscript'], exports = 'env')
SConscript(['dae2ogre/SConscript'], exports = 'env')


Help("""
The build process using scons allows you to set several options. All of the are
explained above. However, not all combinations have been tested and some of them
might not work. A list of teste combinations will be listed here in near future.
""")



