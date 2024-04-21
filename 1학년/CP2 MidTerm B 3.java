package lab07;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Bracket {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String tmp="";
        int cnt=0;
        while(true){
            tmp=br.readLine();
            if (tmp.contains("-")){
                break;
            }
            cnt++;
            int open = 0;
            int ans=0;
            for(String s : tmp.split("")){
                if(s.equals("{")){
                    open+=1;
                } else {
                    if (open>0){
                        open-=1;
                    } else {
                        ans+=1;
                        open+=1;
                    }
                }
            }
            System.out.println(cnt+  ". " + (ans+open/2));
        }
        br.close();
    }
}
