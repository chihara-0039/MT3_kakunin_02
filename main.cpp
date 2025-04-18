#include <Novice.h>

const char kWindowTitle[] = "LE2C_21_チハラ_シゴウ_MT3_kakunin_02";

struct Vector2 {
	float x;
	float y;
};

struct Matrix4x4 {
	float m[4][4];
};

//1.行列の加法
Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			result.m[i][j] = m1.m[i][j] + m2.m[i][j];
	return result;
}

//2.行列の減法
Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			result.m[i][j] = m1.m[i][j] - m2.m[i][j];
	return result;
}

//3.行列の積
Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
	Matrix4x4 result{};
	for (int row = 0; row < 4; ++row)
		for (int col = 0; col < 4; ++col)
			for (int k = 0; k < 4; ++k)
				result.m[row][col] += m1.m[row][k] * m2.m[k][col];
	return result;
}

//4.逆行列
Matrix4x4 Inverse(const Matrix4x4& m) {
	Matrix4x4 result{};

	// 上位3x3の逆行列を計算（ここでは転置＝回転部分の逆）
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			result.m[i][j] = m.m[j][i];

	// 平行移動の逆を計算（R^-1 * -T）
	for (int i = 0; i < 3; ++i) {
		result.m[i][3] = 0.0f;
		for (int j = 0; j < 3; ++j)
			result.m[i][3] -= result.m[i][j] * m.m[j][3];
	}

	// 最後の行は固定
	result.m[3][0] = result.m[3][1] = result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}

//5.転置行列
Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 result{};
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			result.m[i][j] = m.m[j][i];
	return result;
}

//6.単位行列の作成
Matrix4x4 MakeIdentity() {
	Matrix4x4 result{};
	for (int i = 0; i < 4; ++i)
		result.m[i][i] = 1.0f;
	return result;
}

static const int kRowHeight = 20;
static const int kColumnWidth = 60;

void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix) {
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + row * kRowHeight, "%6.02f", matrix.m[row][column]);
		}
	}
}


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
