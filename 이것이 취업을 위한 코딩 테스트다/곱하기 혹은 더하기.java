import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void cal(int index, int sum) {
        if (index + 1 == len) {
            res = Integer.max(res, sum);
            return;
        }
        cal(index + 1, sum + (arr.charAt(index + 1) - '0'));
        cal(index + 1, sum * (arr.charAt(index + 1) - '0'));
    }

    public static String arr;
    public static int len, res = 0;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = st.nextToken();
        len = arr.length();

        cal(0, arr.charAt(0) - '0');
        System.out.println(res);
        br.close();
    }
}