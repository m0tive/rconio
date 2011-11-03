require 'rubygems' unless ENV['NO_RUBYGEMS']
require 'rubygems/package_task'
require 'rake/extensiontask'

spec = Gem::Specification.new do |s|
  s.name = "rconio"
  s.version = "0.0.1"
  s.license = "MIT"
  s.author = "Peter Dodds"
  s.email = "peter@pddds.com"
  s.homepage = "https://github.com/m0tive/rconio"
  s.summary = "A wrapper for MS-DOS conio.h"
  s.description = "RConio is a wrapper for MS-DOS conio.h"

  s.platform = Gem::Platform::CURRENT
  s.has_rdoc = false
  s.extra_rdoc_files = ["README.rdoc", "LICENSE"]

  s.require_path = 'lib'

  s.files = FileList["ext/**/*.{c,rb}", "Rakefile", "README.rdoc", "LICENSE"]
  s.extensions = FileList["ext/**/extconf.rb"]
end

task :default => :compile

Rake::ExtensionTask.new('rconio', spec) do |ext|
  ext.cross_compile = false
end

Gem::PackageTask.new(spec) do |pkg|
  pkg.need_zip = false
  pkg.need_tar = false
end

task :test => [:compile] do
  ruby %q(-Ilib -rrconio -e "puts 'done'")
end

desc "install the gem locally"
task :install => [:package] do
  sh %{sudo gem install pkg/#{GEM}-#{GEM_VERSION}}
end

