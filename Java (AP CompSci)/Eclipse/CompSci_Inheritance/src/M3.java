class M3{
   private int x, y;
   public M3() { x=8;  y=1; }
   public double fun() { return x; }
   public double go() { return y; }
   public double back() { return fun(); }
   public String toString() { 
      return x + " " + y;
   }
}
