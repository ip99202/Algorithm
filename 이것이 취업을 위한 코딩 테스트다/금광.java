import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static int t, n, m;
    public static int[][] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        t = Integer.parseInt(st.nextToken());
        for (int q = 0; q < t; q++) {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
            m = Integer.parseInt(st.nextToken());
            arr = new int[n + 1][m + 1];
            int tmp[][] = new int[n + 1][m + 1];
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                    tmp[i][j] = arr[i][j];
                }
            }
            for (int i = m; i > 1; i--) {
                for (int j = n; j > 0; j--) {
                    for (int k = -1; k <= 1; k++) {
                        if (j + k <= 0 || j + k > n)
                            continue;
                        tmp[j + k][i - 1] = Integer.max(tmp[j + k][i - 1], tmp[j][i] + arr[j + k][i - 1]);
                    }
                }
            }
            int res = 0;
            for (int i = 1; i < m; i++) {
                res = Integer.max(res, tmp[i][1]);
            }
            System.out.println(res);
        }
        br.close();
    }
}
