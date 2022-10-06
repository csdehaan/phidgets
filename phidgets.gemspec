
lib = File.expand_path('../lib/', __FILE__)
$:.unshift lib unless $:.include?(lib)

require 'phidgets/version'

Gem::Specification.new do |s|
  s.name = "phidgets"
  s.version = Phidgets::VERSION
  s.license = 'GPL-2.0'
  s.authors = ["Craig DeHaan"]
  s.email = ["csdehaan2@gmail.com"]
  s.homepage = "https://github.com/csdehaan/phidgets"
  s.summary = "Phidgets are a set of \"plug and play\" building blocks for low cost USB sensing and control from your PC.\nThis gem provides a ruby interface to the phidgets library."
  s.description = "This gem provides a ruby interface to the phidgets library."
  s.executables = ["phidget"]
  s.extensions = ["ext/phidgets/extconf.rb"]
  s.extra_rdoc_files = ["GNU_GPL.txt", "History.txt", "README.rdoc"]
  s.files = Dir.glob("bin/*") +
            Dir.glob("ext/**/*.{c,h}") +
            Dir.glob("lib/**/*.rb")+
            Dir.glob("test/*.rb")+
            %w(Rakefile GNU_GPL.txt History.txt README.rdoc phidgets.gemspec .yardopts)
  s.post_install_message = "For more information on phidgets, see http://www.phidgets.com/"
  s.rdoc_options = ["--main", "README.rdoc"]
  s.require_paths = ["lib", "ext/phidgets"]
end
