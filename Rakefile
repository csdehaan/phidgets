# -*- ruby -*-

require 'rubygems'
require 'rake/extensiontask'
require 'rake/packagetask'
require 'rdoc/task'

spec = Gem::Specification.load('phidgets.gemspec')

Rake::ExtensionTask.new 'phidgets', spec

Gem::PackageTask.new(spec) do |pkg|
  

end

RDOC_FILES = FileList["README.rdoc", "ext/phidgets/*.c", "lib/phidgets/*.rb"]

Rake::RDocTask.new do |rd|
  rd.main = "README.rdoc"
  rd.rdoc_dir = "doc/site/api"
  rd.rdoc_files.include(RDOC_FILES)
end

Rake::RDocTask.new(:ri) do |rd|
  rd.main = "README.rdoc"
  rd.rdoc_dir = "doc/ri"
  rd.options << "--ri-system"
  rd.rdoc_files.include(RDOC_FILES)
end

