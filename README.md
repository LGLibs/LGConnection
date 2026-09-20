# LGConnection

iOS wrapper around AFNetworking makes it easy to use.

## Installation

### With source code

- [Download repository](https://github.com/LGLibs/LGConnection/archive/master.zip), then add [LGConnection directory](./LGConnection) to your project.
- Also you need to install libraries:
  - [AFNetworking](https://github.com/AFNetworking/AFNetworking)
  - [Reachability](https://github.com/tonymillion/Reachability)
  - [XMLReader](https://github.com/RyanCopley/XMLReader)
  - [LGHelper](https://github.com/LGLibs/LGHelper)
  - [LGHelper+NS](https://github.com/LGLibs/LGHelper-NS)

### With CocoaPods

[CocoaPods](http://cocoapods.org) is a dependency manager for Objective-C, which automates and simplifies the process of using 3rd-party libraries in your projects. See the "Get Started" section for more details.

#### Podfile
```
platform :ios, '6.0'
pod 'LGConnection', '~> 1.0.0'
```

## Usage

In the source files where you need to use the library, import the header file:

```objective-c
#import "LGConnection.h"
```

### Initialization

You have several methods for initialization:

```objective-c
- (instancetype)initWithRepeatAfterConnectionLost:(BOOL)repeat;

- (instancetype)initWithRepeatAfterConnectionLost:(BOOL)repeat
                            connectionLostHandler:(void(^)())connectionLostHandler
                         connectionRestoreHandler:(void(^)())connectionRestoreHandler;
```

LGConnection use Reachability to watch for internet connection. "RepeatAfterConnectionLost" means that if connection is lost, then all requests will try to reconnect while connection is restoring.

### More

For more details see [LGConnection.h](./LGConnection/LGConnection.h)

## Repos / Mirrors

- [TRULAB](https://trulab.ru/LGLibs/LGConnection)
- [GitHub](https://github.com/LGLibs/LGConnection)
- [GitLab](https://gitlab.com/LGLibs/LGConnection)
- [Gitea](https://gitea.com/LGLibs/LGConnection)

## License

Copyright (c) 2015 Grigorii Lutkov \<grigorii@lutkov.dev\></br>
Licensed under the [MIT License](./LICENSE)
