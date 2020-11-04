/*
CMain中的几种单例，类都标记为final，表示它们不能作为其他类型的基类。现在我们要定义一个表示总统的类型President，
可以从该类型继承出FrenchPresident和AmericanPresident等类型。
这些派生类型都只能产生一个实例。请问该如何实现？
*/

abstract class President{
    private String name = "";
    private String country = "";
    public President() { }

    public President(String country)
    {
        this.country = country;
    }

    public President(String name, String country)
    {
        this.name = name;
        this.country = country;
    }

    public String getName(){return this.name;}

    public String getCountry(){return this.country;}
}

final class FrenchPresident extends President{
    private FrenchPresident() {
        super("France");
    }

    // 静态内部类，只初始化一次
    private static class SingletonClassHolder{
        static final FrenchPresident president = new FrenchPresident();
    }

    // 只在外部类 调用 静态内部类 时才初始化静态内部类
    public static FrenchPresident getPresident() {
        return SingletonClassHolder.president;
    }
}


final class AmericanPresident extends President{
    private AmericanPresident() {
        super("America");
    }

    // 静态内部类，只初始化一次
    private static class SingletonClassHolder{
        static final AmericanPresident president = new AmericanPresident();
    }

    // 只在外部类 调用 静态内部类 时才初始化静态内部类
    public static AmericanPresident getPresident() {
        return SingletonClassHolder.president;
    }
}

public class EMain {
    public static void main(String[] args) {
        President frenchPresident = FrenchPresident.getPresident();
        President americanPresident = AmericanPresident.getPresident();

        System.out.println(frenchPresident != americanPresident);
        System.out.println(frenchPresident == FrenchPresident.getPresident());
        System.out.println(americanPresident == AmericanPresident.getPresident());
    }
}