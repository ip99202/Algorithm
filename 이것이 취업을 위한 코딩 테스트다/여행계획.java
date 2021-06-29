import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class UnionFind {

    public static int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    public static void union(int x, int y) {
        x = find(x);
        y = find(y);
        parent[y] = x;
    }

    public static boolean isUnoin(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return true;
        return false;
    }

    public static int n, m;
    public static int[] parent;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        parent = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                int x = Integer.parseInt(st.nextToken());
                if (x == 1) {
                    union(i, j);
                }
            }
        }
        boolean res = true;
        int plan[] = new int[m];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            plan[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 1; i < m; i++) {
            if (!isUnoin(plan[i], plan[i - 1])) {
                res = false;
            }
        }
        if (res)
            System.out.println("YES");
        else
            System.out.println("NO");
        br.close();
    }
}
