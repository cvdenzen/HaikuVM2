import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
import java.util.TreeMap;
import java.util.Vector;


public class Statistic {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException, IOException {
		//sizesOfFoos();
		buildJUnitStat();
	}

	
	private static void buildJUnitStat() throws IOException {
	    Map<String, Vector<String>> table = new TreeMap<String, Vector<String>>();
        BufferedReader bi= new BufferedReader(new FileReader("src/test/resources/junit.log"));
        String line, lastline=null, testee="";
        for(int i=1; (line=bi.readLine())!=null; i++) {
            if (line.startsWith("##########  ")) {
                lastline=line;
                String list[]= line.split("[ ]+");
                if (testee!=null) {
                    Vector<String> row = table.get(testee);
                    if (row==null) {
                        row=new Vector<String>();
                    }
                    if (list[1].equals("elapsed")) {
                        row.add(list[3]);
                    } 
//                    if (list[1].equals("Program:")) {
//                        row.add(list[2]);
//                    }
                    table.put(testee, row);
                }
            } else {
                if (lastline!=null) {
                    String list[]= lastline.split("[ ]+");
                    testee=list[1];
                    lastline=null;
                }
            }

        }
        bi.close();
        
        for (String key : table.keySet()) {
            Vector<String> row = table.get(key);
            System.out.printf("%s\t", key);
            for (String value : row) {
                System.out.printf("%s\t", value);
            }
            System.out.printf("\n");
        }
    }


    private static void sizesOfFoos() throws FileNotFoundException, IOException {
		class Desc {

			private String foo;
			private int len;

			public Desc(String foo, int len) {
				this.foo=foo;
				this.len=len;
			}
			
		};
		Vector<Desc> foos=new Vector<Desc>();
		//BufferedReader bi= new BufferedReader(new FileReader("../arduinoApp/Release/asuroApp.lss"));
		BufferedReader bi= new BufferedReader(new FileReader("../avrTest2/Release/avrTest2.lss"));
		String foo=null, bl="";
		int p0=0, p1=0;
		int s=0;
		String line;
		for(int i=1; (line=bi.readLine())!=null; i++) {
			if (line.matches(".+ <.+>:")) {
				String list[]= line.split("[ <>:]+");
				p1=Integer.parseInt(list[0], 16);
				if(foo!=null) {
					p0=p1-p0;
					foos.add(new Desc(foo, p0));
				}
				foo=list[1];
				p0=p1;
			} else if (foo!=null && foo.startsWith("bytecodeLabels") && line.length()>10) {
				String list[]= line.substring(0, "     3f8:	14 03 14 03 14 03 7b 03 a0 03 a9 03 20 03 a9 03".length()).split("\\s+");
				for (int j = 2; j < list.length; j+=2) {
					String hex=list[j+1]+list[j];
					int h=Integer.parseInt(hex, 16);
					if (s==0) s=h;
					bl+=hex+"\t"+h+"\t"+(h-s)+"\n";
				}
			}

		}
		
		Collections.sort(foos, new Comparator<Desc>() {
			   public int compare(Desc o1, Desc o2){
			      return Integer.valueOf(o1.len).compareTo(o2.len);
			   }
			});
		int sum=0;
		for (int i = 0; i < foos.size(); i++) {
			sum+=foos.get(i).len;
			System.out.printf("%4d    %4d    %s\n", i, foos.get(i).len, foos.get(i).foo);
		}
		System.out.printf("sum     %4d\n", sum);
		System.out.println(bl);
	}


}
