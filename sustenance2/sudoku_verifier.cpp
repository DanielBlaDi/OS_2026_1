#include <iostream>
#include <fstream>

using namespace std;


bool sudo_load(string s_file_name, int s_matrix[9][9]){

    int m_size = 9;
    
    // Se usa para abrir el archivo txt
    ifstream s_file(s_file_name);

    // Verifica si se abrio
    if (!s_file.is_open()) {
        cerr << "Error: No se pudo abrir el archivo '" << s_file_name << "'." << endl;
        return false;
    }
    
    // Buclecito anidado para guardar la info en la matriz
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            s_file >> s_matrix[i][j];
        }
    }
    
    // Se cierra el archivo
    s_file.close();
    
    // Preatty print para ver el sudoku, se puede borrar
    cout << "--- Sudoku cargado exitosamente ---" << endl;
    for (int i = 0; i < m_size; ++i) {
        // Separador visual para las regiones de 3x3 (filas)
        if (i > 0 && i % 3 == 0) {
            cout << "------+------+------" << endl;
        }
        
        for (int j = 0; j < m_size; ++j) {
            // Separador visual para las regiones de 3x3 (columnas)
            if (j > 0 && j % 3 == 0) {
                cout << "| ";
            }
            cout << s_matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return true;

}



int main() {

    // Crea la matriz para guardar info
    int s_matrix[9][9];

    // Name del doc
    string s_file_name = "sudoku.txt";
    
    if (!sudo_load(s_file_name, s_matrix)) {
        cerr << "Error: No se pudo cargar el sudoku." << endl;
        return 1;
    }

    return 0;
}
