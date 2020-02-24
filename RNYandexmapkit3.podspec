require "json"

package = JSON.parse(File.read(File.join(__dir__, "package.json")))

Pod::Spec.new do |s|
  s.name         = "RNYandexmapkit3"
  s.version      = package["version"]
  s.summary      = "Yandex Map Kit 3 React Native support package"
  s.homepage     = "https://github.com/dmitryermichev/react-native-yandexmapkit3"
  s.license      = "MIT"
  s.author             = { "Dmitry Ermichev" => "dmitryermichev@gmail.com" }
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/dmitryermichev/react-native-yandexmapkit3.git", :tag => "#{s.version}" }

  s.source_files  = "ios/**/*.{h,m}"

  s.dependency 'YandexMapKit', '~> 3.2.0'
end
