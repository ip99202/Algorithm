import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Pair {
    int x, y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class main {
    public static int[][] arr = new int[201][201];
    public static int[][] visited = new int[201][201];
    public static Queue<Pair> q = new LinkedList<>();

    public static int[] dx = {0, 0, 1, -1};
    public static int[] dy = {1, -1, 0, 0};
    public static int n, m;

    public static int bfs() {
        while (!q.isEmpty()) {
            Pair pair = q.poll();
            if (pair.x == n && pair.y == m)
                break;

            for (int i = 0; i < 4; i++) {
                int nx = pair.x + dx[i];
                int ny = pair.y + dy[i];
                if (nx <= 0 || nx > n || ny <= 0 || ny > m)
                    continue;
                if (visited[nx][ny] != 0)
                    continue;
                visited[nx][ny] = visited[pair.x][pair.y] + 1;
                q.add(new Pair(nx, ny));

            }
        }
        return visited[n][m] + 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < n; i++) {
            String tmp = sc.nextLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = tmp.charAt(j) - '0';
                visited[i][j] = 0;
            }
        }

        q.add(new Pair(1, 1));
        System.out.println(bfs());
    }
}
