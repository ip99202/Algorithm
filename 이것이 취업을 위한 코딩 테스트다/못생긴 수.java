import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {

    public static int n, m;
    public static ArrayList<Integer> arr = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        arr.add(1);
        int i2 = 0, i3 = 0, i5 = 0;
        int n2 = 2, n3 = 3, n5 = 5;
        for (int i = 1; i <= n; i++) {
            arr.add(Math.min(Math.min(n2,n3),n5));
            if (arr.get(i) == n2) {
                i2++;
                n2 = arr.get(i2) * 2;
            }
            if (arr.get(i) == n3) {
                i3++;
                n3 = arr.get(i3) * 3;
            }
            if (arr.get(i) == n5) {
                i5++;
                n5 = arr.get(i5) * 5;
            }
        }
        System.out.println(arr.get(n - 1));
        br.close();
    }
}
