require 'rubygems'
gem 'hoe', '>= 2.1.0'
require 'hoe'
require 'fileutils'
require './lib/phidgets'

Hoe.plugin :newgem

# Generate all the Rake tasks
# Run 'rake -T' to see list of generated tasks (from gem root directory)
$hoe = Hoe.spec 'phidgets' do
  self.developer 'Craig DeHaan', 'craig.s.dehaan@gmail.com'
  self.post_install_message = 'PostInstall.txt'
  self.rubyforge_name       = self.name

end

require 'newgem/tasks'
Dir['tasks/**/*.rake'].each { |t| load t }

