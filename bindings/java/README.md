> See the [root README](../../README.md) for a general overview of WBTP.

Here's some Java bindings for ***lib*WBTP**!

They don't depend on natives, instead reimplementing the spec from scratch. This implementation has a large focus on procedural-style code, but we also provide both `WbtpResponse` and `WbtpRequest` object-oriented wrappers to ensure usability.

### Short Library Overview

|Class|Description|
|---|---|
|`WbtpRequest`|Object-oriented instance-based wrapper for WbtpRequests.|
|`WbtpResponse`|Object-oriented instance-based wrapper for WbtpResponses.|
|`WbtpRequests`|Provides utilities for quickly and properly transforming request data.|
|`WbtpResponses`|Provides utilities for quickly and properly transforming response data.|
|`WbtpRequestData`|Data describing a request.|
|`WbtpResponseData`|Data describing a response.|

### Setup

To install ***lib*WBTP** in your Gradle project, simply include our library hosted on Maven Central:

```kotlin
dependencies {
    implementation("io.github.boyninja1555:wbtp-java:${VERSION}")
}
```

And in your Maven project:

```xml
<dependency>
    <groupId>io.github.boyninja1555</groupId>
    <artifactId>wbtp-java</artifactId>
    <version>${VERSION}</version>
</dependency>
```
