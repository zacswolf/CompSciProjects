class P4 
{
   private int x, y;   

   public P4() { x=7;  y=0;  }
   public P4(int v){x=v; y=7;}
   
   public double fun() { return x; }
   public void go() { back();  } 
   public void whoot() { go(); }
   public void back() { 
      x=992; 
   }
   public String toString() 
   { 
      return getClass().getName() + " "  + x + " " + y;
   }
}
