import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.*;

class NormalObject {
}

// 只适用于单线程
final class LazyInitSingleton1 {
    private LazyInitSingleton1() {
    }

    private static LazyInitSingleton1 instance = null;

    public static LazyInitSingleton1 getInstance() {
        if (instance == null) {
            try {
                Thread.sleep(1);
            } catch (final InterruptedException e) {
                e.printStackTrace();
            }
            instance = new LazyInitSingleton1();
        }
        return instance;
    }
    
}

// 加同步锁，可以确保线程不会冲突 从而导致创建多个实例
// 缺点 每次获取实例都会加锁 非常耗时
final class LazyInitSingleton2 {
    private LazyInitSingleton2() {
    }

    private static final Object syncObj = new Object();

    private static LazyInitSingleton2 instance = null;

    public static LazyInitSingleton2 getInstance() {
        synchronized (syncObj) {
            if (instance == null) {
                try {
                    Thread.sleep(1);
                } catch (final InterruptedException e) {
                    e.printStackTrace();
                }
                instance = new LazyInitSingleton2();
            }
        }
        return instance;
    }
}

// 加同步锁，可以确保线程不会冲突 从而导致创建多个实例
final class LazyInitSingleton3 {
    private LazyInitSingleton3() {
    }

    private static final Object syncObj = new Object();

    private static LazyInitSingleton3 instance = null;

    public static LazyInitSingleton3 getInstance() {
        if (instance == null) {
            synchronized (syncObj) {
                if (instance == null) {
                    try {
                        Thread.sleep(1);
                    } catch (final InterruptedException e) {
                        e.printStackTrace();
                    }
                    instance = new LazyInitSingleton3();
                }
            }
        }

        return instance;
    }

    public static void reset() {
        instance = null;
    }
}

// 在加载类时构造
final class EagerInitSingleton1 {
    private EagerInitSingleton1() {
    }

    private static final EagerInitSingleton1 instance = new EagerInitSingleton1();

    public static EagerInitSingleton1 getInstance() {
        return instance;
    }
}

// 在加载类时 使用静态块构造
final class EagerInitSingleton2 {
    private EagerInitSingleton2() {
    }

    private static EagerInitSingleton2 instance;

    // 使用静态块构造
    static {
        instance = new EagerInitSingleton2();
    }

    public static EagerInitSingleton2 getInstance() {
        return instance;
    }
}

// 在加载类时 使用静态块构造
final class LazyInitNestedSingleton {
    private LazyInitNestedSingleton() {
    }

    // 静态内部类，只初始化一次
    private static class SingletonClassHolder{
        static final LazyInitNestedSingleton instance = new LazyInitNestedSingleton();
    }

    // 只在外部类 调用 静态内部类 时才初始化静态内部类
    public static LazyInitNestedSingleton getInstance() {
        return SingletonClassHolder.instance;
    }
}

class CMain {

    static void TestSingleton(final Class c) {
        System.out.println();
        System.out.println("Test " + c.getName() + " begin");

        Method getInstance;
        try {
            getInstance = c.getMethod("getInstance");

        } catch (final Exception e) {
            e.printStackTrace();
            return;
        }
        
        final List<Object> instances = new LinkedList<Object>();
        final Vector<Object> vInstances = new Vector<Object>();

        for (int i = 0; i < 10; i++) {
            new Thread(new Runnable() {
                @Override
                public void run() {
                    Object instance;
                    try {
                        instance = getInstance.invoke(null);
                        instances.add(instance);
                        vInstances.add(instance);
                    } catch (IllegalAccessException | IllegalArgumentException | InvocationTargetException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }

        while (true) {
            if (vInstances.size() == 10)
                break;
        }

        // List 是线程不安全的，会报错
        // for(Singleton1 instance : instances){
        // System.out.println(Singleton1.getInstance() == instance); // true
        // }

        final Set<Object> set = new HashSet<Object>(vInstances);
        final int instanceCount = set.size();
        System.out.println("创建了" + instanceCount + "个实例:");
        for (final Object instance : set) {
            System.out.print(instance + "\t");
        }
        System.out.println();
        System.out.println("-------------------");

        if(instanceCount == 1) return;

        for (int i = 0; i < vInstances.size(); i++) {
            for (int j = 0; j < vInstances.size(); j++) {
                System.out.print((vInstances.get(i) == vInstances.get(j)) + "\t");
            }
            System.out.println();
        }
        System.out.println("-------------------");
        System.out.println("TestSingleton1 end");
    }

    static void TestNormalObject() {
        System.out.println("TestNormalObject begin");
        System.out.println(new NormalObject() == new NormalObject()); // false
        System.out.println("-------------------");
        System.out.println("TestNormalObject end");
    }

    public static void main(final String[] args) {
        TestNormalObject();
        TestSingleton(LazyInitSingleton1.class);
        TestSingleton(LazyInitSingleton1.class);
        TestSingleton(LazyInitSingleton2.class);
        TestSingleton(LazyInitSingleton3.class);
        TestSingleton(EagerInitSingleton1.class);
        TestSingleton(EagerInitSingleton2.class);
        TestSingleton(LazyInitNestedSingleton.class);
    }
}