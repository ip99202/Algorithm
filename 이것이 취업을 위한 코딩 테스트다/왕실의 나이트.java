import java.util.Scanner;

public class main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        int row = input.charAt(1) - '0';
        int col = input.charAt(0) - 'a' + 1;

        int[] dx = {-2, -1, 1, 2, 2, 1, -1, -2};
        int[] dy = {-1, -2, -2, -1, 1, 2, 2, 1};

        int res = 0;
        for (int i = 0; i < 8; i++) {
            int nx = row + dx[i];
            int ny = col + dy[i];
            if (nx > 0 && nx <= 8 && ny > 0 && ny <= 8)
                res++;
        }
        System.out.println(res);
    }
}
