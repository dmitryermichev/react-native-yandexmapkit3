require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "react-native-yandexmapkit3"
  s.version      = package["version"]
  s.summary      = package["description"]
  s.description  = <<-DESC
                  react-native-yandexmapkit3
                   DESC
  s.homepage     = "https://github.com/dmitryermichev/react-native-yandexmapkit3"
  s.license      = "MIT"
  # s.license    = { :type => "MIT", :file => "FILE_LICENSE" }
  s.authors      = { "Dmitry Ermichev" => "dmitryermichev@gmail.com" }
  s.platforms    = { :ios => "9.0", :tvos => "10.0" }
  s.source       = { :git => "https://github.com/dmitryermichev/react-native-yandexmapkit3.git", :tag => "#{s.version}" }

  s.source_files = "ios/**/*.{h,m,swift}"
  s.requires_arc = true
  s.swift_version = '4.0'

  s.dependency "React"

  s.dependency 'YandexMapKit', '~> 3.4'
  s.resource_bundle = {'react-native-yandexmapkit3' => ['ios/**/*.{xcassets,storyboard}']}
end

