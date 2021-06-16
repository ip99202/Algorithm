import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static String a, b;
    public static int[][] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        a = st.nextToken();
        st = new StringTokenizer(br.readLine());
        b = st.nextToken();
        arr = new int[a.length() + 1][b.length() + 1];
        arr[0][0] = 0;
        arr[0][1] = 0;
        arr[1][0] = 0;
        for (int i = 0; i < b.length(); i++) {
            arr[0][i + 1] = i + 1;
        }
        for (int i = 0; i < a.length(); i++) {
            arr[i + 1][0] = i + 1;
        }
        for (int i = 1; i <= a.length(); i++) {
            for (int j = 1; j <= b.length(); j++) {
                if (a.charAt(i - 1) == b.charAt(j - 1)) {
                    arr[i][j] = arr[i - 1][j - 1];
                } else {
                    arr[i][j] = Math.min(arr[i - 1][j - 1], Math.min(arr[i - 1][j], arr[i][j - 1])) + 1;
                }
            }
        }
        System.out.println(arr[a.length()][b.length()]);
        br.close();
    }
}
