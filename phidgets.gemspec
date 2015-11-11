# -*- encoding: utf-8 -*-
lib = File.expand_path('../lib/', __FILE__)  
$:.unshift lib unless $:.include?(lib)

require 'phidgets'

Gem::Specification.new do |s|
  s.name = "phidgets"
  s.version = Phidgets::VERSION
  s.authors = ["Craig DeHaan"]
  s.email = ["cdehaan2@cfl.rr.com"]
  s.homepage = "https://github.com/csdehaan/phidgets"
  s.summary = "Phidgets are a set of \"plug and play\" building blocks for low cost USB sensing and control from your PC.\nThis gem provides a ruby interface to the phidgets library."
  s.description = "This gem provides a ruby interface to the phidgets library."

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.executables = ["phidget"]
  s.extensions = ["ext/phidgets/extconf.rb"]
  s.extra_rdoc_files = ["GNU_GPL.txt", "History.txt", "README.rdoc"]
  s.files = Dir.glob("bin/*") +
            Dir.glob("ext/**/*.{c,h}") +
            Dir.glob("lib/**/*.rb")+
            Dir.glob("test/*.rb")+
            %w(Rakefile GNU_GPL.txt History.txt README.rdoc phidgets.gemspec .yardopts)
  s.test_files = Dir.glob("test/*.rb")
  s.post_install_message = "For more information on phidgets, see http://www.phidgets.com/"
  s.rdoc_options = ["--main", "README.rdoc"]
  s.require_paths = ["lib", "ext/phidgets"]
  s.rubygems_version = "1.8.25"

  if s.respond_to? :specification_version then
    s.specification_version = 3

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<rdoc>, ["~> 3.10"])
      s.add_development_dependency("rake-compiler")
    else
      s.add_dependency(%q<rdoc>, ["~> 3.10"])
      s.add_dependency("rake-compiler")
    end
  else
    s.add_dependency(%q<rdoc>, ["~> 3.10"])
    s.add_dependency("rake-compiler")
  end

end
