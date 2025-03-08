# Project Layout

## Without the VSCode Starter Project

Initialize the official CodeQL repository as a submodule in your project directory:

```sh
git submodule add https://github.com/github/codeql.git ql
```

Add `qlpack.yml` next to your .ql files:

```yml
name: codeql-cheat-sheet-cpp
version: 0.0.1
libraryPathDependencies: codeql-cpp
```

Add `queries.xml` next to yout .ql files:

```xml
<queries language="cpp"/>
```
