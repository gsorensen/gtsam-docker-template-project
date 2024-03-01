# Docker container for GTSAM development

Build from root directory using
```
docker build -f Dockerfile -t "<name_here>"  .
```

Run the executable like so 
```
docker run <name_here> ./build/ExampleProject
```
where ExampleProject is just the current name for the executable defined in
CMakeLists.txt

### Issues / potential improvements

- compile_commands.json linting not fully cooked on macOS, assume would work
fine on Linux. Need to add lines copying this file to host after build
- Change entrypoint correctly to run the executable so you don't have to specify
  it in the terminal
