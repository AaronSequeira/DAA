public class Strassen {

	public int[][] multiply(int[][] A, int[][] B)
	{
		int n = A.length;
		int[][] R = new int[n][n];
		if (n == 1)
			R[0][0] = A[0][0] * B[0][0];

		else {
			int[][] A11 = new int[n / 2][n / 2];
			int[][] A12 = new int[n / 2][n / 2];
			int[][] A21 = new int[n / 2][n / 2];
			int[][] A22 = new int[n / 2][n / 2];
			int[][] B11 = new int[n / 2][n / 2];
			int[][] B12 = new int[n / 2][n / 2];
			int[][] B21 = new int[n / 2][n / 2];
			int[][] B22 = new int[n / 2][n / 2];

			//split
			for(int i=0;i<n/2;i++){
				for(int j=0;j<n/2;j++){
					A11[i][j] = A[i][j];
					A12[i][j] = A[i][j+n/2];
					A21[i][j] = A[i+n/2][j];
					A22[i][j] = A[i+n/2][j+n/2];

					B11[i][j] = B[i][j];
					B12[i][j] = B[i][j+n/2];
					B21[i][j] = B[i+n/2][j];
					B22[i][j] = B[i+n/2][j+n/2];
				}
			}

			int[][] M1= multiply(add(A11, A22), add(B11, B22));
			int[][] M2 = multiply(add(A21, A22), B11);
			int[][] M3 = multiply(A11, sub(B12, B22));
			int[][] M4 = multiply(A22, sub(B21, B11));
			int[][] M5 = multiply(add(A11, A12), B22);
			int[][] M6= multiply(sub(A21, A11), add(B11, B12));
			int[][] M7= multiply(sub(A12, A22), add(B21, B22));

			int[][] C11 = add(sub(add(M1, M4), M5), M7);
			int[][] C12 = add(M3, M5);
			int[][] C21 = add(M2, M4);
			int[][] C22 = add(sub(add(M1, M3), M2), M6);
			
			//join
			for(int i=0;i<n/2;i++){
				for(int j=0;j<n/2;j++){
					R[i][j] = C11[i][j];
					R[i][j+n/2] = C12[i][j];
					R[i+n/2][j] = C21[i][j];
					R[i+n/2][j+n/2] = C22[i][j];
				}
			}

		}
		return R;
	}

	public int[][] sub(int[][] A, int[][] B)
	{
		int n = A.length;
		int[][] C = new int[n][n];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				C[i][j] = A[i][j] - B[i][j];

		return C;
	}

	public int[][] add(int[][] A, int[][] B)
	{
		int n = A.length;
		int[][] C = new int[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				C[i][j] = A[i][j] + B[i][j];

		return C;
	}

	public static void main(String[] args)
	{
		System.out.println("Strassen Multiplication Algorithm Implementation For Matrix Multiplication :\n");
		Strassen s = new Strassen();

		int N = 4;
		int[][] A ={{ 0, 0, 3, 4 },
                    { 5, 6, 0, 0 },
                    { 0, 0, 6, 5 },
                    { 4, 3, 0, 0 }};

        int[][] B ={{ 0, 0, 6, 5 },
                    { 4, 3, 0, 0 },
                    { 0, 0, 3, 4 },
                    { 5, 6, 0, 0 }};

		int[][] C = s.multiply(A, B);
		System.out.println("\nProduct of matrices A and B : ");

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				System.out.print(C[i][j] + " ");
			System.out.println();
		}
	}
}
