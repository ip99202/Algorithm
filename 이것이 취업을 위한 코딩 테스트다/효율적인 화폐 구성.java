import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] coin = new int[n];
        for (int i = 0; i < n; i++)
            coin[i] = Integer.parseInt(br.readLine());

        int[] dp = new int[m + 1];
        Arrays.fill(dp, 10001);
        dp[0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coin[j] < 0) continue;
                dp[i] = Math.min(dp[i], dp[i - coin[j]] + 1);
            }
        }
        if (dp[m] == 10001)
            System.out.println(-1);
        else
            System.out.println(dp[m]);
        br.close();
    }
}