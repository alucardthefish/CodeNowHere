class HelloWorld
{
    constructor()
    {
        background $.output("Hello, world!");
    }
    output($arg)
    {
        printf("%s\n", $arg);
    }
}

new HelloWorld();
