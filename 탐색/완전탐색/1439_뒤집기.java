import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static String arr;
    public static int len;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = st.nextToken();
        len = arr.length();

        int zero = 0, one = 0;
        boolean flag = true;
        for (int i = 1; i < len; i++) {
            if (arr.charAt(i - 1) != arr.charAt(i)) {
                if (arr.charAt(i - 1) == '0')
                    zero++;
                else
                    one++;
                flag = false;
            }
            if (i == len - 1)
                if (arr.charAt(i) == '0')
                    zero++;
                else
                    one++;
        }
        if (flag)
            System.out.println(0);
        else if (one * zero == 0)
            System.out.println(Integer.max(zero, one));
        else
            System.out.println(Integer.min(zero, one));
        br.close();
    }
}