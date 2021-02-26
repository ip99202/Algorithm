import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static int n;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            if (n == 0) break;
            String arr = br.readLine();
            int len = arr.length();

            int[] check = new int[128];
            int right = -1, left = -1, cnt = 0, res = 0;

            while (left <= right) {
                if (cnt < n || (cnt == n && check[arr.charAt(right + 1)] > 0)) {
                    right++;
                    check[arr.charAt(right)]++;
                    if (check[arr.charAt(right)] == 1)
                        cnt++;

                } else {
                    left++;
                    check[arr.charAt(left)]--;
                    if (check[arr.charAt(left)] == 0)
                        cnt--;
                }
                res = Math.max(right - left, res);
                if (right == len - 1)
                    break;
            }
            System.out.println(res);
        }
        br.close();
    }
}