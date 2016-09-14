
public class LANG {
	private int grades;
	
	LANG(int[] topfourLangSemesters){
		for(int i=0; i < topfourLangSemesters.length;i++){
			grades = topfourLangSemesters[i];
		}
		grades = grades/topfourLangSemesters.length;
	}
	public int getAVG(){
		return grades;
	}

}
