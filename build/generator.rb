if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

INCLUDE ||= []
CORTEX_LIB ||= []
LFLAGS ||= []
LIBPATH ||= []

TARGETDIR = "#{ENV['CORTEX_HOME']}/generator/bin"
CORTEX_LIB << "cortex"
LIBPATH << "#{ENV['CORTEX_HOME']}/bin"
INCLUDE << "#{ENV['CORTEX_HOME']}/cx/include"
LFLAGS << "--shared"
ARTEFACT = TARGET

require "#{ENV['CORTEX_HOME']}/build/artefact"