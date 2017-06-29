using System;
using System.Collections.Generic;
using System.Linq;

class MyDate
{
    private int year;
    private int month;
    private int date;
    private bool isLeap;
    
    private int index = 0;
    
    public static List<MyDate> SkipDates = null;
    
    private static bool isLeapYear(int year)
    {
        if(year%4!=0)return false;
        if(year%100!=0)return true;
        if(year%400!=0)return false;
        return true;
    }
    
    private void calcIndex()
    {
        this.index = 0;
        
        for(int y=0;y<year;y++)
        {
            if(isLeapYear(y))
            {
                this.index+=366;
            }
            else
            {
                this.index+=365;
            }
        }
        
        int[] monthDays = new int[]{31,this.isLeap ? 29:28,31,30,31,30,31,31,30,31,30,31};
        
        int m = month-1;
        this.index += this.date;
        while(m>0)
        {
            m--;
            this.index += monthDays[m];
        }
    }
    
    private void checkDate()
    {
        if(year<=0 || year>9999)
        {
            throw new Exception("Invalid Date");
        }
        if(month<=0 || month>=13)
        {
            throw new Exception("Invalid Date");
        }
        if(date<=0)
        {
            throw new Exception("Invalid Date");
        }
        
        if(month==1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            if(date>=32)
            {
                throw new Exception("Invalid Date");
            }
        }
        else if(month != 2)
        {
            if(date>=31)
            {
                throw new Exception("Invalid Date");
            }
        }
        else
        {
            if(this.isLeap)
            {
                if(date>=30)
                {
                    throw new Exception("Invalid Date");
                }
            }
            else
            {
                if(date>=29)
                {
                    throw new Exception("Invalid Date");
                }
            }
        }
    }
    
    public MyDate(int year, int month, int date)
    {
        this.isLeap = isLeapYear(year);
        
        this.year = year;
        this.month = month;
        this.date = date;
     
        checkDate();
        
        calcIndex();
    }
    
    public static int operator-(MyDate firstDate, MyDate secondDate)
    {
        if(firstDate == null || secondDate == null)
            return 0;
        int result = firstDate.index - secondDate.index;
        if(SkipDates == null || SkipDates.Count == 0)
            return result;
        int skip = SkipDates.Where(d=>(d.index-firstDate.index)*(d.index-secondDate.index)<0).Count();
        skip = result > 0 ? skip : -skip;
        return result - skip;
    }
}
 
public class Test
{
	public static void Main()
	{
	    MyDate.SkipDates = new List<MyDate>{new MyDate(2017,6,5),new MyDate(2017,6,1)};
		MyDate firstDate = new MyDate(2017,7,1);
		MyDate secondDate = new MyDate(2017,6,2);
		Console.WriteLine(firstDate-secondDate);
	}
}
