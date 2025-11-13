# Index 

## Repository

Source and sample code is available here: https://github.com/v-p-b/codeql-cheat-sheet 

PR's welcome!

## Project Layout

### Without the VSCode Starter Project

Initialize the official CodeQL repository as a submodule in your project directory:

```sh
git submodule add https://github.com/github/codeql.git ql
```

Add `qlpack.yml` next to your .ql files:

```yml
name: codeql-cheat-sheet-cpp
version: 0.0.1
dependencies: 
  codeql/cpp-all: "^1.0.0" 
```

Note: the legacy `libraryPathDependencies` syntax won't work! The official way to do things is using the `codeql pack` CLI commands. 


Add `queries.xml` next to yout .ql files:

```xml
<queries language="cpp"/>
```

Use `codeql pack install` to install dependencies of your queries.
