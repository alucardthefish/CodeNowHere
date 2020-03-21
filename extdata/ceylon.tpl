void hello(String? name) {
    if (exists name) {
        print("Hello, ``name``!");
    }
    else {
        print("Hello, world!");
    }
}