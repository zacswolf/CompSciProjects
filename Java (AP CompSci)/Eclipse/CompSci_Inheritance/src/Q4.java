class Q4 extends P4 
{
   private int x;

   public Q4() { x=23;  } 
   public Q4(int v) { super(v); x=33;  }
   
   public double fun() { return x; }
   public void go() { back();  }
   public void back() { 
      x=45; 
   }

   public String toString() 
   { 
      return "class " + getClass().getName() + " " + x
                      + " " +  super.toString() ;
   }
}
