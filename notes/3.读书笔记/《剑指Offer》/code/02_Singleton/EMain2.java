/*
CMain中的几种单例，类都标记为final，表示它们不能作为其他类型的基类。现在我们要定义一个表示总统的类型President2，
可以从该类型继承出FrenchPresident2和AmericanPresident2等类型。
这些派生类型都只能产生一个实例。请问该如何实现？
*/

class President2{
    private String name = "";
    private String country = "";
    public President2() { }

    public President2(String country)
    {
        this.country = country;
    }

    public President2(String name, String country)
    {
        this.name = name;
        this.country = country;
    }

    public String getName(){return this.name;}

    public String getCountry(){return this.country;}

    // 静态内部类，只初始化一次
    private static class SingletonClassHolder{
        static final President2 President2 = new President2();
    }

    // 只在外部类 调用 静态内部类 时才初始化静态内部类
    public static President2 getPresident2() {
        return SingletonClassHolder.President2;
    }
}

final class FrenchPresident2 extends President2{
    private FrenchPresident2() {
        super("France");
    }
}


final class AmericanPresident2 extends President2{
    private AmericanPresident2() {
        super("America");
    }
}

public class EMain2 {
    public static void main(String[] args) {
        President2 frenchPresident2 = FrenchPresident2.getPresident2();
        President2 americanPresident2 = AmericanPresident2.getPresident2();

        System.out.println(frenchPresident2 != americanPresident2);
        System.out.println(frenchPresident2 == FrenchPresident2.getPresident2());
        System.out.println(americanPresident2 == AmericanPresident2.getPresident2());
    }
}