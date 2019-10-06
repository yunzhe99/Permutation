import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Random;

public class Test{	
public static List<String> getList(String[][]a){		
Random r=new Random();		
List<String> strs=new ArrayList<String>();		
int n=1;		
//计算共有多少种情况 总数为所有数组长度的积	
for(int i=0;i<a.length;i++){			
n*=a[i].length;		
}		
for(int i=0;i<n;i++){			
String c="";
//int index = 0;
for(int j=0;j<a.length;j++){
	//每一个数组里取一个随机元素				
int index=r.nextInt(a[j].length);//随机数的范围是这个数组的长度
//String[] aa = new String[a.length];
//for (int k=0;k<aa.length;k++)
//{
//	if( aa[k] == a[j][index])
//	{
//		j = j-1;
//		break;
//	}
//	aa[j] = a[j][index];
	///if(index >= a[j].length-1)
	//	index = 0;
	//else
	//	index++;
	
	//if(c.contains(a[j][index]))	
		//j--;
	//else
		c+=a[j][index];			
//}
}			
//判断集合中是否含有这个元素,有则总数+1,无则添加到这个集合中		
if(strs.contains(c)){				
n++;			
}else{				
strs.add(c);			
}		
}		
Collections.sort(strs);//最后排序一下	
return strs;	
}	

//public static String[][] TwoArry(String[] arr2){
//    String[][] arr=new String[1][arr2.length];
//    for (int i = 0; i < arr2.length; i++) {
//        arr[0][i]=arr2[i];
 //   }
//    return arr;
//}


//public static String[] strChange(String str1[],  int start, int end){
	
//	int k = end - start;
//	String str2[] = new String[k];
//	for(int i = start, j=0 ; i<end && j<k; i++,j++){
//		str2[j] = str1[i];
//	}
	
//	return str2;
//}



public static void main(String[] args) {		
	long startTime = System.currentTimeMillis(); 
	//File csv = new File(
	//		"/home/liyunzhe/Desktop/从n个数组中取出所有排列组合(Java实现)/defgroup.csv"); // CSV文件路径
	//BufferedReader br = null;
	//try {
	//	br = new BufferedReader(new FileReader(csv));
	//} catch (FileNotFoundException e) {
	//	e.printStackTrace();
	//}
	//String line = "";
	//String everyLine = "";

	
	//try {
		//List<String> allString = new ArrayList<>();
		//String[][] a = {{""}};
		//int x = 0;
		//while ((line = br.readLine()) != null) // 读取到的内容给line变量
		//{
		//	everyLine = line;
			//String[] arr = everyLine.split(","); // 用,分割
			//System.out.println(Arrays.toString(arr)); // [0, 1, 2, 3, 4, 5]
			//a[x] = arr;
			
			//x++;
			
		//	System.out.println(everyLine);
			
		//	allString.add(everyLine);
		//}
		
		//String[][][] c = {{{""}}};
		
		//int m = 0;
		
		//System.out.println(a[0][0]);
		//System.out.println(a[1][0]);
		 
		//for (int i = 0; i < a.length-1; i++) {
	    //        while(a[i][0] != a[i+1][0])
	     //       {
	            	
	     //       	for(int j = 2; j < a[i].length; j++)
	      //      	{
	     //       		String[] b = strChange(a[i],2,a[i].length+1);
	      //      		c[m] = TwoArry(b);		            		
	      //      	}
	            		
	        //    }
	        //    List<String>strs=getList(c[m]);
            //	m++;
            //	for(String s:strs){			
            //		System.out.println(s);	
	            	
	            	//String[][] b = TwoArry(a)
	         //   }
	           
	            	
	            
		 //}
		
		//System.out.println("csv表格中所有行数：" + allString.size());
	//} catch (IOException e) {
	//	e.printStackTrace();
	//}
	String[][]a={{" 1"," 2"},{" 1"," 2"},{" 3"," 4"},{" 3"," 4"},{" 5"},{" 6"," 7"," 8"," 9"},{" 6"," 7"," 8"," 9"},{" 6"," 7"," 8"," 9"},{" 6"," 7"," 8"," 9"},{" 10"},{" 11"}};		
List<String>strs=getList(a);
String filePath = "/home/liyunzhe/Desktop/从n个数组中取出所有排列组合(Java实现)/output.txt";
for(String s:strs){			
System.out.println(s);	

FileWriter fwriter = null;
try {
     //true表示不覆盖原来的内容，而是加到文件的后面。若要覆盖原来的内容，直接省略这个参数就好
    fwriter = new FileWriter(filePath, true);
    fwriter.write(s+"\n");
} catch (IOException ex) {
    ex.printStackTrace();
} finally {
    try {
        fwriter.flush();
        fwriter.close();
    } catch (IOException ex) {
        ex.printStackTrace();
    }
}

}		
System.out.println("共有"+strs.size()+"个");	

	
	
long endTime = System.currentTimeMillis(); //程序结束记录时间
long TotalTime = endTime - startTime; 
System.out.println("耗时" + TotalTime + "ms");
}

}