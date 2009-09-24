#!/usr/bin/ruby

# Given a Visual Studio project, create a CMakeLists.txt file to serve
# as a starting point. Supports simple DLL/Static/Executable projects,
# but custom build steps and build events are ignored.

# Author: Jesper Eskilson 
# Email: jesper [at] eskilson [dot] se
# Version: 1.0

require 'fileutils'
require 'rexml/document'
include FileUtils::Verbose

configuration="Debug|Win32"

# Usage: vcproj2cmake.rb <input.vcproj> [<output CMakeLists.txt>]

filename = ARGV.shift
output_file = ARGV.shift or output_file = File.join(File.dirname(filename), "CMakeLists.txt")

# Change \ to /, and remove leading ./
def normalize(p)
  felems = p.gsub("\\", "/").split("/")
  felems.shift if felems[0] == "."
  File.join(felems)
end

if File.exists?(output_file)
  mv(output_file, output_file + ".backup")
end

File.open(output_file, "w") { |out|
  File.open(filename) { |io|
    doc = REXML::Document.new io
    
    doc.elements.each("VisualStudioProject") { |project|
      name = project.attributes["Name"]
      
      out.puts "project( #{name} )"

      out.puts
      out.puts( "set(SOURCES " )
      
      project.elements.each("Files//File") { |file|
        
        f = normalize(file.attributes["RelativePath"])

        # Ignore header files
        next if f =~ /\.(h|H|lex|y|ico|bmp|txt)$/

        # Ignore files which have the ExcludedFromBuild attribute set to TRUE
        excluded_from_build = false
        file.elements.each("FileConfiguration") { |file_config|
          if file_config.attributes["ExcludedFromBuild"] == "TRUE"
            excluded_from_build = true
          end
        }
        
        # Ignore files with custom build steps
        included_in_build = true
        file.elements.each("FileConfiguration/Tool") { |tool|
          if tool.attributes["Name"] == "VCCustomBuildTool"
            included_in_build = false
          end
        }
        
        if not excluded_from_build and included_in_build
          out.puts "  " + f
        end

      }

      out.puts ")"

      project.elements.each("Configurations/Configuration[@Name=\"#{configuration}\"]") { |config|
        config_name = config.attributes["Name"].split("|")[0]
        
        # 0 == no MFC
        # 1 == static MFC
        # 2 == shared MFC
        use_of_mfc = config.attributes["UseOfMFC"].to_i
        if use_of_mfc > 0
          out.puts
          out.puts "set(CMAKE_MFC_FLAG #{use_of_mfc})"
        end


        config.elements.each('Tool[@Name="VCCLCompilerTool"]') { |compiler|

          out.puts
          out.puts "include_directories( \n"

          include_dirs = compiler.attributes["AdditionalIncludeDirectories"].split(/[,;]/).sort.each { |s|
            incpath = normalize(s).strip
            if incpath["Vc7/atlmfc/src/mfc"]
              out.puts "  ${MFC_INCLUDE}"
            else
              out.puts "  " + incpath
            end
          }
          out.puts ")"
          
          out.puts
          out.puts "add_definitions( \n"
          compiler.attributes["PreprocessorDefinitions"].split(";").sort.each { |s|
            out.puts "  -D" + s.strip
          }

          if use_of_mfc == 2
            out.puts "  -D_AFXEXT"
            out.puts "  -D_AFXDLL"
          end
          
          out.puts ")"

        }

        config_type = config.attributes["ConfigurationType"].to_i
        
        out.puts

        if config_type == 1    # Executable
          out.puts "add_executable( #{name} WIN32 ${SOURCES} )"
        elsif config_type == 2    # DLL
          out.puts "add_library( #{name} SHARED ${SOURCES} )"
        elsif config_type == 4    # Static
          out.puts "add_library( #{name} STATIC ${SOURCES} )"
        else
          $stderr.puts "Project type #{config_type} not supported."
          exit 1
        end
 
        out.puts
        config.elements.each('Tool[@Name="VCLinkerTool"]') { |linker|
          deps = linker.attributes["AdditionalDependencies"]
          if deps and deps.length > 0
            out.print "target_link_libraries( #{name} "

            deps.split.each  { |lib|
              lib = lib.gsub(/\\/, "/")
              out.print File.basename(lib, ".lib") + " "
            }

            out.puts ")"
          end
        }
      }
    }
  }
}

puts "Wrote #{output_file}"

