#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Equipo {
   private:
    string nombre;
    string nombreEntrenador;

   public:
    Equipo();
    Equipo(string, string);
    ~Equipo();

    string getNombre();
    string getNombreEntrenador();

    void setNombre(string);
    void setNombreEntrenador(string);

    string toString();
};

Equipo::Equipo() {
}

Equipo::Equipo(string nombre, string nombreEntrenador) {
    this->nombre = nombre;
    this->nombreEntrenador = nombreEntrenador;
}

Equipo::~Equipo() {
}

string Equipo::getNombre() {
    return nombre;
}

string Equipo::getNombreEntrenador() {
    return nombreEntrenador;
}

void Equipo::setNombre(string nombre) {
    this->nombre = nombre;
}

void Equipo::setNombreEntrenador(string nombreEntrenador) {
    this->nombreEntrenador = nombreEntrenador;
}

string Equipo::toString() {
    return "Nombre: " + this->nombre + ", nombre del entrenador: " + this->nombreEntrenador;
}

class Partido {
   private:
    Equipo equipoLocal;
    Equipo equipoVisitante;
    string tipo;
    string resultado;

   public:
    Partido(Equipo, Equipo, string);
    ~Partido();

    Equipo getEquipoLocal();
    Equipo getEquipoVisitante();
    string getTipo();
    string getResultado();

    void setEquipoLocal(Equipo);
    void setEquipoVisitante(Equipo);
    void setTipo(string);
    void setResultado(string);

    string toString();
};

Partido::Partido(Equipo equipoLocal, Equipo equipoVisitante, string tipo) {
    this->equipoLocal = equipoLocal;
    this->equipoVisitante = equipoVisitante;
    this->tipo = tipo;
}

Partido::~Partido() {
}

Equipo Partido::getEquipoLocal() {
    return equipoLocal;
}

Equipo Partido::getEquipoVisitante() {
    return equipoVisitante;
}

string Partido::getTipo() {
    return tipo;
}

string Partido::getResultado() {
    return resultado;
}

void Partido::setEquipoLocal(Equipo equipoLocal) {
    this->equipoLocal = equipoLocal;
}

void Partido::setEquipoVisitante(Equipo equipoVisitante) {
    this->equipoVisitante = equipoVisitante;
}

void Partido::setTipo(string tipo) {
    this->tipo = tipo;
}

void Partido::setResultado(string resultado) {
    this->resultado = resultado;
}

string Partido::toString() {
    return "Equipo local: " + this->equipoLocal.toString() + ", equipo visitante: " + this->equipoVisitante.toString() + ", tipo: " + tipo + "\n";
}

int main(int argc, char const *argv[]) {
    Equipo eq1("Equipo 1", "Entrenador 1");
    Equipo eq2("Equipo 2", "Entrenador 2");
    Equipo eq3("Equipo 3", "Entrenador 3");
    Equipo eq4("Equipo 4", "Entrenador 4");

    vector<Equipo> equipos = {eq1, eq2, eq3, eq4};

    vector<Partido> partidos;

    int numPartidos = (equipos.size() - 1) * 2;

    for (int i = 0; i < equipos.size() - 1; i++) {
        for (int j = i; j < equipos.size() - 1; j++) {
            cout << i << endl;
            Partido partidoIda(equipos.at(i), equipos.at(j + 1), "IDA");
            Partido partidoVuelta(equipos.at(j + 1), equipos.at(i), "Vuelta");
            partidos.push_back(partidoIda);
            partidos.push_back(partidoVuelta);
        }
    }

    for (int i = 0; i < partidos.size(); i++) {
        cout << "Partido numero " + to_string(i + 1) + " " + partidos.at(i).toString();
    }

    //Pedir resultados
    string resultado;
    for (int i = 0; i < partidos.size(); i++) {
        cout << "Introduce el resultado del partido numero " + to_string(i + 1) + " " + partidos.at(i).toString();
        getline(cin, resultado);
        partidos.at(i).setResultado(resultado);
    }

    //Mostrar resultados
    for (int i = 0; i < partidos.size(); i++) {
        cout << "Local:  " + partidos.at(i).getEquipoLocal().getNombre() + " Visitante: " + partidos.at(i).getEquipoVisitante().getNombre() + " Resultado: " + partidos.at(i).getResultado() << endl;
    }

    return 0;
}