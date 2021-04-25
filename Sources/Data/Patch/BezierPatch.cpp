/* Classe que define um patch de Bezier
MDCC-UFC: Mestrado e Doutorado em Ciências da Computação
Universidade Federal do Ceará
Implementação da dissertação de Mestrado
Título: Geração Adaptativa de Malhas de Superfície com Controle de Curvatura
Autor: Daniel Márcio Batista de Siqueira
contato: siqueira@lia.ufc.br
Orientador: Creto Augusto Vidal
Co-Orientador: Joaquim Bento Cavalcante
This source code is under GNU General Public License v3 */

#include "../../../Headers/Data/Patch/BezierPatch.h"

extern double TOLERANCIA; // distância máxima entre dois pontos

Matrix4x4 iniciaMatrizBezier ( )
{
    //    m->setElement( 0, 0,-1 ); m->setElement( 0, 1, 3 ); m->setElement( 0, 2,-3 ); m->setElement( 0, 3, 1 );
    //    m->setElement( 1, 0, 3 ); m->setElement( 1, 1,-6 ); m->setElement( 1, 2, 3 ); m->setElement( 1, 3, 0 );
    //    m->setElement( 2, 0,-3 ); m->setElement( 2, 1, 3 ); m->setElement( 2, 2, 0 ); m->setElement( 2, 3, 0 );
    //    m->setElement( 3, 0, 1 ); m->setElement( 3, 1, 0 ); m->setElement( 3, 2, 0 ); m->setElement( 3, 3, 0 );

    Matrix4x4 B;

    B(0,0) = -1; B(0,1) = 3;  B(0,2) = -3; B(0,3) = 1;
    B(1,0) = 3;  B(1,1) = -6; B(1,2) = 3;  B(1,3) = 0;
    B(2,0) = -3; B(2,1) = 3;  B(2,2) = 0;  B(2,3) = 0;
    B(3,0) = 1;  B(3,1) = 0;  B(3,2) = 0;  B(3,3) = 0;

    return B;
}


void BezierPatch::mostraMatrizes ( )
{
    cout << "U:\n" << U;
    //  this->getU().getElement( 0, 0 ) <<" "<< this->getU().getElement( 0, 1 ) <<" "<< this->getU().getElement( 0, 2 ) <<" "<< this->getU().getElement( 0, 3 ) << endl;
    cout << "B:\n" << B;
    //            this->getB().getElement( 0, 0 ) <<" "<< this->getB().getElement( 0, 1 ) <<" "<< this->getB().getElement( 0, 2 ) <<" "<< this->getB().getElement( 0, 3 ) << "\n" <<
    //            this->getB().getElement( 1, 0 ) <<" "<< this->getB().getElement( 1, 1 ) <<" "<< this->getB().getElement( 1, 2 ) <<" "<< this->getB().getElement( 1, 3 ) << "\n" <<
    //            this->getB().getElement( 2, 0 ) <<" "<< this->getB().getElement( 2, 1 ) <<" "<< this->getB().getElement( 2, 2 ) <<" "<< this->getB().getElement( 2, 3 ) << "\n" <<
    //            this->getB().getElement( 3, 0 ) <<" "<< this->getB().getElement( 3, 1 ) <<" "<< this->getB().getElement( 3, 2 ) <<" "<< this->getB().getElement( 3, 3 ) << endl;

    cout << "Gx:\n" << Gx;
    //            this->getGx().getElement( 0, 0 ) <<" "<< this->getGx().getElement( 0, 1 ) <<" "<< this->getGx().getElement( 0, 2 ) <<" "<< this->getGx().getElement( 0, 3 ) << "\n" <<
    //            this->getGx().getElement( 1, 0 ) <<" "<< this->getGx().getElement( 1, 1 ) <<" "<< this->getGx().getElement( 1, 2 ) <<" "<< this->getGx().getElement( 1, 3 ) << "\n" <<
    //            this->getGx().getElement( 2, 0 ) <<" "<< this->getGx().getElement( 2, 1 ) <<" "<< this->getGx().getElement( 2, 2 ) <<" "<< this->getGx().getElement( 2, 3 ) << "\n" <<
    //            this->getGx().getElement( 3, 0 ) <<" "<< this->getGx().getElement( 3, 1 ) <<" "<< this->getGx().getElement( 3, 2 ) <<" "<< this->getGx().getElement( 3, 3 ) << endl;

    cout << "Gy:\n" << Gy;
    //            this->getGy().getElement( 0, 0 ) <<" "<< this->getGy().getElement( 0, 1 ) <<" "<< this->getGy().getElement( 0, 2 ) <<" "<< this->getGy().getElement( 0, 3 ) << "\n" <<
    //            this->getGy().getElement( 1, 0 ) <<" "<< this->getGy().getElement( 1, 1 ) <<" "<< this->getGy().getElement( 1, 2 ) <<" "<< this->getGy().getElement( 1, 3 ) << "\n" <<
    //            this->getGy().getElement( 2, 0 ) <<" "<< this->getGy().getElement( 2, 1 ) <<" "<< this->getGy().getElement( 2, 2 ) <<" "<< this->getGy().getElement( 2, 3 ) << "\n" <<
    //            this->getGy().getElement( 3, 0 ) <<" "<< this->getGy().getElement( 3, 1 ) <<" "<< this->getGy().getElement( 3, 2 ) <<" "<< this->getGy().getElement( 3, 3 ) << endl;

    cout << "Gz:\n" << Gz;
    //            this->getGz().getElement( 0, 0 ) <<" "<< this->getGz().getElement( 0, 1 ) <<" "<< this->getGz().getElement( 0, 2 ) <<" "<< this->getGz().getElement( 0, 3 ) << "\n" <<
    //            this->getGz().getElement( 1, 0 ) <<" "<< this->getGz().getElement( 1, 1 ) <<" "<< this->getGz().getElement( 1, 2 ) <<" "<< this->getGz().getElement( 1, 3 ) << "\n" <<
    //            this->getGz().getElement( 2, 0 ) <<" "<< this->getGz().getElement( 2, 1 ) <<" "<< this->getGz().getElement( 2, 2 ) <<" "<< this->getGz().getElement( 2, 3 ) << "\n" <<
    //            this->getGz().getElement( 3, 0 ) <<" "<< this->getGz().getElement( 3, 1 ) <<" "<< this->getGz().getElement( 3, 2 ) <<" "<< this->getGz().getElement( 3, 3 ) << endl;

    cout << "V:\n" << V;
    //            this->getV().getElement( 0, 0 ) << "\n" <<
    //            this->getV().getElement( 1, 0 ) << "\n" <<
    //            this->getV().getElement( 2, 0 ) << "\n" <<
    //            this->getV().getElement( 3, 0 ) << endl;
}


// encontra o parâmetro t de um dado ponto p na curva
tuple < double, double > BezierPatch::encontrar_u_v ( const Ponto& p )
{
    unsigned int iMax = 0;

    // chute inicial
    double u_i = 0.5;
    double v_i = 0.5;
    ////////////////

    double delta_u = 0.0; // o quanto o parâmetro terá de percorrer
    double delta_v = 0.0; // o quanto o parâmetro terá de percorrer

    // Método de Jacobi para resolução de sistema
    Ponto p_i;
    //cout << "encontrar_u_v (" << p.id << "), usando Jacobi!";

    do
    {
        //#pragma omp critical
        //        cout<<"u_i: "<<u_i<<" v_i: "<<v_i<<" thread: "<<omp_get_thread_num()<<endl;

        Vetor Tu = -(this->Qu(u_i, v_i));
        Vetor Tv = -(this->Qv(u_i, v_i));

        p_i = this->parametrizar ( u_i, v_i ); // palpite inicial

//        if (std::isnan(p_i.x)) {
//#pragma omp critical
//            {
//                cout<<"-nan pi"<<endl;
//                cout<<"u_i: "<<u_i<<" v_i: "<<v_i<<" thread: "<<omp_get_thread_num()<<endl;
//                cout<< p_i.id << " (" << p.x << ", " << p.y << ", " << p.z << ") thread: "<<omp_get_thread_num()<< endl;
//            }
//        }

        Matrix<double, 3,3> A;
        A(0,0) = Tu.x;	A(0,1) = Tv.x;	A(0,2) = p_i.x - p.x;
        A(1,0) = Tu.y;	A(1,1) = Tv.y;	A(1,2) = p_i.y - p.y;
        A(2,0) = Tu.z;	A(2,1) = Tv.z;	A(2,2) = p_i.z - p.z;

        //        Vector3d b= {p.x, p.y, p.z};
        //        cout<<A.colPivHouseholderQr().solve(b)<<endl;

        int k = 0;
        double pivo = A(0,0);

        while ((fabs(pivo) < TOLERANCIA) and (k < 2))
        {
            ++k;
            pivo = A(k,0);
        }

        A.row(k).swap(A.row(0));

        if ( fabs(pivo) < TOLERANCIA )
        {
            cout << "Erro! Não é possível encontrar as coordenadas paramétricas no ponto p"
                 << p.id << " (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;

            return make_tuple ( -1.0 , -1.0 );
        }

        double A_10 = A(1,0);
        double A_20 = A(2,0);

        for ( short j = 0; j < 3 ; ++j )
        {
            A(0,j) = static_cast<double >(A(0, j))/pivo;
            A(1,j) = A(1,j) - A_10*(A(0,j));
            A(2,j) = A(2,j) - A_20*(A(0,j));
        }

        pivo = A(1,1);

        if ( fabs(pivo) < TOLERANCIA )
        {
            pivo = A(2,1);
            A.row(2).swap(A.row(1));
        }

        double A_01 = A(0,1);
        double A_21 = A(2,1);

        for ( short j = 0; j < 3 ; ++j )
        {
            A(1,j) = static_cast<double>(A(1,j)/pivo);
            A(0,j) = A(0,j) - A_01*(A(1,j));
            A(2,j) = A(2,j) - A_21*(A(1,j));
        }


        delta_u =  A(0,2);
        delta_v =  A(1,2);

//        if (std::isnan(delta_u) || std::isnan(delta_v)){
//#pragma omp critical
//            {
//                cout<<"-nan delta_u e delta_v"<<endl;
//                cout<<"delta_u: "<<delta_u<<" delta_v: "<<delta_v<<" thread: "<<omp_get_thread_num()<<endl;
//            }
//        }

        if (!std::isnan(delta_u)){
            u_i += delta_u;
        }

        if (!std::isnan(delta_v)){
            v_i += delta_v;
        }



        if ( ++iMax > 50000 )
        {
#if USE_PRINT_COMENT
            cout << "iMax alcançado!" << endl;
#endif //#if USE_PRINT_COMENT

            break;
        }
        //cout << "u = " << u_i << " " << "v = " << v_i << endl;
        //cout << "delta_u = " << delta_u << " " << "delta_v = " << delta_v << endl;
    }
    while ( fabs ( delta_u ) >= TOLERANCIA or fabs ( delta_v ) >= TOLERANCIA );
    //while ( p.distanciaPara(p_i) >= TOLERANCIA );

    if ( u_i <= TOLERANCIA ) u_i = 0.0;
    else if ( u_i >= 1.0 - TOLERANCIA ) u_i = 1.0;

    if ( v_i <= TOLERANCIA ) v_i = 0.0;
    else if ( v_i >= 1.0 - TOLERANCIA ) v_i = 1.0;

    if (std::isnan(u_i) || std::isnan(v_i)) {
        cout<<"-nan u_i e v_i"<<endl;
    }

    return make_tuple ( u_i, v_i );
}

tuple<double, double> BezierPatch::find_u_v(const Ponto &p)
{
    return make_tuple(-1,-1);
}


// faz as multiplicações necessárias para 'parametrizar ( u, v )' e para as
// derivadas parciais
Matrix1x4 BezierPatch::getU() const {
    return this->U;
}

Matrix4x4 BezierPatch::getGx() const {
    return this->Gx;
}

Matrix4x4 BezierPatch::getGy() const {
    return this->Gy;
}

Matrix4x4 BezierPatch::getGz() const {
    return this->Gz;
}

Matrix4x1 BezierPatch::getV() const {
    return this->V;
}

Matrix4x4 BezierPatch::getB() const {
    return this->B;
}

Ponto BezierPatch::calculaPonto_u_v ()
{
    //  ALOCA um Ponto e o retorna
    //
    Ponto C;

    // C = ( U * ( B * ( G * ( Bt * V ) ) ) )

    C.x =	(	this->getU  ( ) *
                (	//this->getB  ( ) *
                    (	this->getGx ( ) *
                        ( 	//this->getB  ( ) *   // só é getB ao invés de getB().transposta pois a matriz de Bezier é simétrica
                            this->getV  ( ) ) ) ) )( 0, 0 );

    C.y =	(	this->getU  ( ) *
                (	//this->getB  ( ) *
                    (	this->getGy ( ) *
                        ( 	//this->getB  ( ) *   // só é getB ao invés de getB().transposta pois a matriz de Bezier é simétrica
                            this->getV  ( ) ) ) ) )( 0, 0 );

    C.z =	(	this->getU  ( ) *
                (	//this->getB  ( ) *
                    (	this->getGz ( ) *
                        (	//this->getB  ( ) *   // só é getB ao invés de getB().transposta pois a matriz de Bezier é simétrica
                            this->getV  ( ) ) ) ) )( 0, 0 );

    //	cout << "calculaPonto_u_v () = " << C.x << " " << C.y << " " << C.z << endl;
    return C;
}

Ponto BezierPatch::getPt00() const {
    return this->Pt00;
}

Ponto BezierPatch::getPt01() const {
    return this->Pt01;
}

Ponto BezierPatch::getPt02() const {
    return this->Pt02;
}

Ponto BezierPatch::getPt03() const {
    return this->Pt03;
}

Ponto BezierPatch::getPt10() const {
    return this->Pt10;
}

Ponto BezierPatch::getPt11() const {
    return this->Pt11;
}

Ponto BezierPatch::getPt12() const {
    return this->Pt12;
}

Ponto BezierPatch::getPt13() const {
    return this->Pt13;
}

Ponto BezierPatch::getPt20() const {
    return this->Pt20;
}

Ponto BezierPatch::getPt21() const {
    return this->Pt21;
}

Ponto BezierPatch::getPt22() const {
    return this->Pt22;
}

Ponto BezierPatch::getPt23() const {
    return this->Pt23;
}

Ponto BezierPatch::getPt30() const {
    return this->Pt30;
}

Ponto BezierPatch::getPt31() const {
    return this->Pt31;
}

Ponto BezierPatch::getPt32() const {
    return this->Pt32;
}

Ponto BezierPatch::getPt33() const {
    return this->Pt33;
}

void BezierPatch::setPt00(Ponto value){
    Pt00 = value;
}

void BezierPatch::setPt01(Ponto value){
    Pt01 = value;
}

void BezierPatch::setPt02(Ponto value){
    Pt02 = value;
}

void BezierPatch::setPt03(Ponto value){
    Pt03 = value;
}

void BezierPatch::setPt10(Ponto value){
    Pt10 = value;
}

void BezierPatch::setPt11(Ponto value){
    Pt11 = value;
}

void BezierPatch::setPt12(Ponto value){
    Pt12 = value;
}

void BezierPatch::setPt13(Ponto value){
    Pt13 = value;
}

void BezierPatch::setPt20(Ponto value){
    Pt20 = value;
}

void BezierPatch::setPt21(Ponto value){
    Pt21 = value;
}

void BezierPatch::setPt22(Ponto value){
    Pt22 = value;
}

void BezierPatch::setPt23(Ponto value){
    Pt23 = value;
}

void BezierPatch::setPt30(Ponto value){
    Pt30 = value;
}

void BezierPatch::setPt31(Ponto value){
    Pt31 = value;
}

void BezierPatch::setPt32(Ponto value){
    Pt32 = value;
}

void BezierPatch::setPt33(Ponto value){
    Pt33 = value;
}


// encontra as coordenadas 3D de um ponto p de parâmetros u, v
Ponto BezierPatch::parametrizar ( double u, double v )
{
    //	cout << "parametrizar ( " << u << ", " << v << ")" << endl;
    // parametrizar:
    //
    //  -> ALTERA a matriz U
    //  -> ALTERA a matriz V
    //  -> usa 'calculaPonto_u_v ( )'
    //

    this->U(0,0) = u*u*u;
    this->U(0,1) = u*u;
    this->U(0,2) = u;
    this->U(0,3) = 1;

    this->V(0,0) = v*v*v;
    this->V(1,0) = v*v;
    this->V(2,0) = v;
    this->V(3,0) = 1;

    return calculaPonto_u_v ();
}


// calcula o vetor tangente na direção u nas coordenadas paramétricas u, v
Vetor BezierPatch::Qu ( double u, double v )
{
    // Qt:
    //
    //  -> ALOCA um Ponto (mas destroi aqui mesmo)
    //	 -> ALOCA um Vetor (retorna ele)
    //  -> ALTERA a matriz U !!!
    //  -> ALTERA a matriz V !!!
    //

    Ponto P;

    this->U( 0, 0) = 3*u*u;
    this->U( 0, 1) = 2*u;
    this->U( 0, 2) = 1;
    this->U( 0, 3) = 0;

    this->V( 0, 0) = v*v*v;
    this->V( 1, 0) = v*v;
    this->V( 2, 0) = v;
    this->V( 3, 0) = 1;

    P = calculaPonto_u_v ();
    Vetor V ( P );

    return V;
}


// calcula o vetor tangente na direção v nas coordenadas paramétricas u, v
Vetor BezierPatch::Qv ( double u, double v )
{
    // Qt:
    //
    //  -> ALOCA um Ponto (mas destroi aqui mesmo)
    //	 -> ALOCA um Vetor (retorna ele)
    //  -> ALTERA a matriz U !!!
    //  -> ALTERA a matriz V !!!
    //

    Ponto P;

    this->U( 0, 0) = u*u*u;
    this->U( 0, 1) = u*u;
    this->U( 0, 2) = u;
    this->U( 0, 3) = 1;

    this->V( 0, 0) = 3*v*v;
    this->V( 1, 0) = 2*v;
    this->V( 2, 0) = 1;
    this->V( 3, 0) = 0;

    P = calculaPonto_u_v ();
    Vetor V ( P );

    return V;
}


// calcula a derivada parcial Quu nas coordenadas paramétricas u, v
Vetor BezierPatch::Quu ( double u, double v )
{
    // Qt:
    //
    //  -> ALOCA um Ponto (mas destroi aqui mesmo)
    //	 -> ALOCA um Vetor (retorna ele)
    //  -> ALTERA a matriz U !!!
    //  -> ALTERA a matriz V !!!
    //

    Ponto P;

    this->U( 0, 0) = 6*u;
    this->U( 0, 1) = 2;
    this->U( 0, 2) = 0;
    this->U( 0, 3) = 0;

    this->V( 0, 0) = v*v*v;
    this->V( 1, 0) = v*v;
    this->V( 2, 0) = v;
    this->V( 3, 0) = 1;


    P = calculaPonto_u_v ();
    Vetor V ( P );

    return V;
}


// calcula a derivada parcial Quv nas coordenadas paramétricas u, v
Vetor BezierPatch::Quv ( double u, double v )
{
    // Qt:
    //
    //  -> ALOCA um Ponto (mas destroi aqui mesmo)
    //	 -> ALOCA um Vetor (retorna ele)
    //  -> ALTERA a matriz U !!!
    //  -> ALTERA a matriz V !!!
    //

    Ponto P;

    this->U( 0, 0) = 3*u*u;
    this->U( 0, 1) = 2*u;
    this->U( 0, 2) = 1;
    this->U( 0, 3) = 0;

    this->V( 0, 0) = 3*v*v;
    this->V( 1, 0) = 2*v;
    this->V( 2, 0) = 1;
    this->V( 3, 0) = 0;

    P = calculaPonto_u_v ();
    Vetor V ( P );

    return V;
}


// calcula a derivada parcial Qvu nas coordenadas paramétricas u, v
Vetor BezierPatch::Qvu ( double u, double v )
{
    return Quv ( u, v );
}


// calcula a derivada parcial Qvv nas coordenadas paramétricas u, v
Vetor BezierPatch::Qvv ( double u, double v )
{
    // Qt:
    //
    //  -> ALOCA um Ponto (mas destroi aqui mesmo)
    //	 -> ALOCA um Vetor (retorna ele)
    //  -> ALTERA a matriz U !!!
    //  -> ALTERA a matriz V !!!
    //

    Ponto P;

    this->U( 0, 0) = u*u*u;
    this->U( 0, 1) = u*u;
    this->U( 0, 2) = u;
    this->U( 0, 3) = 1;

    this->V( 0, 0) = 6*v;
    this->V( 1, 0) = 2;
    this->V( 2, 0) = 0;
    this->V( 3, 0) = 0;

    P = calculaPonto_u_v ();
    Vetor V ( P );

    return V;
}


// calcula o vetor tangente na direção u para o ponto p
Vetor BezierPatch::Qu ( const Ponto& p )
{
    tuple < double, double > t = this->encontrar_u_v ( p );
    return this->Qu ( get < 0 > ( t ), get < 1 > ( t ) );
}


// calcula o vetor tangente na direção v para o ponto p
Vetor BezierPatch::Qv ( const Ponto& p )
{
    tuple < double, double > t = this->encontrar_u_v ( p );
    return this->Qv ( get < 0 > ( t ), get < 1 > ( t ) );
}


// calcula a derivada parcial Quu para o ponto p
Vetor BezierPatch::Quu ( const Ponto& p )
{
    tuple < double, double > t = this->encontrar_u_v ( p );
    return this->Quu ( get < 0 > ( t ), get < 1 > ( t ) );
}


// calcula a derivada parcial Quv para o ponto p
Vetor BezierPatch::Quv ( const Ponto& p )
{
    tuple < double, double > t = this->encontrar_u_v ( p );
    return this->Quv ( get < 0 > ( t ), get < 1 > ( t ) );
}


// calcula a derivada parcial Qvu para o ponto p
Vetor BezierPatch::Qvu ( const Ponto& p )
{
    tuple < double, double > t = this->encontrar_u_v ( p );
    return this->Qvu ( get < 0 > ( t ), get < 1 > ( t ) );
}


// calcula a derivada parcial Qvv para o ponto p
Vetor BezierPatch::Qvv ( const Ponto& p )
{
    tuple < double, double > t = this->encontrar_u_v ( p );
    return this->Qvv ( get < 0 > ( t ), get < 1 > ( t ) );
}


// Ordem das curvas:
//		C3
//	C4		C2
//		C1
BezierPatch::BezierPatch ( Curva* C1, Curva* C2, Curva* C3, Curva* C4,
                           Ponto Pt_11, Ponto Pt_21, Ponto Pt_12, Ponto Pt_22,
                           bool sinal_c1 , bool sinal_c2, bool sinal_c3, bool sinal_c4 ) : CoonsPatch ( )
{
    this->sinal_c1 = sinal_c1;
    this->sinal_c2 = sinal_c2;
    this->sinal_c3 = sinal_c3;
    this->sinal_c4 = sinal_c4;

    // As curvas devem ser definidas da esquerda para a direita, de baixo para
    // cima em relação ao Patch !!!
    // 1. Inclui as curvas na lista de curvas de CoonsPatch
    //
    this->curvas.push_back ( C1 );
    this->curvas.push_back ( C2 );
    this->curvas.push_back ( C3 );
    this->curvas.push_back ( C4 );
    //
    // 2. Coloca o Patch na lista das curvas
    //
    static_cast < CurvParamBezier* > ( C1 )->inserePatch ( this );
    static_cast < CurvParamBezier* > ( C2 )->inserePatch ( this );
    static_cast < CurvParamBezier* > ( C3 )->inserePatch ( this );
    static_cast < CurvParamBezier* > ( C4 )->inserePatch ( this );
    //
    // 3. Seta os atributos de acordo com as curvas
    //
    this->Pt00 = static_cast < CurvParamBezier* > ( C1 )->P0;
    this->Pt10 = static_cast < CurvParamBezier* > ( C1 )->P1;
    this->Pt20 = static_cast < CurvParamBezier* > ( C1 )->P2;

    this->Pt30 = static_cast < CurvParamBezier* > ( C2 )->P0;
    this->Pt31 = static_cast < CurvParamBezier* > ( C2 )->P1;
    this->Pt32 = static_cast < CurvParamBezier* > ( C2 )->P2;

    this->Pt13 = static_cast < CurvParamBezier* > ( C3 )->P1;
    this->Pt23 = static_cast < CurvParamBezier* > ( C3 )->P2;
    this->Pt33 = static_cast < CurvParamBezier* > ( C3 )->P3;

    this->Pt01 = static_cast < CurvParamBezier* > ( C4 )->P1;
    this->Pt02 = static_cast < CurvParamBezier* > ( C4 )->P2;
    this->Pt03 = static_cast < CurvParamBezier* > ( C4 )->P3;

    this->Pt11 = Pt_11;
    this->Pt21 = Pt_21;
    this->Pt12 = Pt_12;
    this->Pt22 = Pt_22;
    //
    // 4. Aloca espaço para as matrizes
    //
    this->U.setZero(1,4);
    this->V.setZero(4,1);
    this->Gx.setZero(4,4);
    this->Gy.setZero(4,4);
    this->Gz.setZero(4,4);
    //
    // 5. Preenche as matrizes geométricas com G de Bezier
    //
    // Gx:
    // 2x2 superior esquerdo
    Gx(0,0) = this->Pt00.x; Gx(0,1) = this->Pt01.x;
    Gx(1,0) = this->Pt10.x; Gx(1,1) = this->Pt11.x;
    // 2x2 inferior esquerdo
    Gx(2,0) = this->Pt20.x; Gx(2,1) = this->Pt21.x;
    Gx(3,0) = this->Pt30.x; Gx(3,1) = this->Pt31.x;
    // 2x2 superior direito
    Gx(0,2) = this->Pt02.x; Gx(0,3) = this->Pt03.x;
    Gx(1,2) = this->Pt12.x; Gx(1,3) = this->Pt13.x;
    // 2x2 inferior direito
    Gx(2,2) = this->Pt22.x; Gx(2,3) = this->Pt23.x;
    Gx(3,2) = this->Pt32.x; Gx(3,3) = this->Pt33.x;
    //
    // Gy:
    // 2x2 superior esquerdo
    this->Gy(0,0) = this->Pt00.y; Gy(0,1) = this->Pt01.y;
    Gy(1,0) = this->Pt10.y; Gy(1,1) = this->Pt11.y;
    // 2x2 inferior esquerdo
    Gy(2,0) = this->Pt20.y; Gy(2,1) = this->Pt21.y;
    Gy(3,0) = this->Pt30.y; Gy(3,1) = this->Pt31.y;
    // 2x2 superior direito
    Gy(0,2) = this->Pt02.y; Gy(0,3) = this->Pt03.y;
    Gy(1,2) = this->Pt12.y; Gy(1,3) = this->Pt13.y;
    // 2x2 inferior direito
    Gy(2,2) = this->Pt22.y; Gy(2,3) = this->Pt23.y;
    Gy(3,2) = this->Pt32.y; Gy(3,3) = this->Pt33.y;
    //
    // Gz:
    // 2x2 superior esquerdo
    Gz(0,0) = this->Pt00.z; Gz(0,1) = this->Pt01.z;
    Gz(1,0) = this->Pt10.z; Gz(1,1) = this->Pt11.z;
    // 2x2 inferior esquerdo
    Gz(2,0) = this->Pt20.z; Gz(2,1) = this->Pt21.z;
    Gz(3,0) = this->Pt30.z; Gz(3,1) = this->Pt31.z;
    // 2x2 superior direito
    Gz(0,2) = this->Pt02.z; Gz(0,3) = this->Pt03.z;
    Gz(1,2) = this->Pt12.z; Gz(1,3) = this->Pt13.z;
    // 2x2 inferior direito
    Gz(2,2) = this->Pt22.z; Gz(2,3) = this->Pt23.z;
    Gz(3,2) = this->Pt32.z; Gz(3,3) = this->Pt33.z;
    //
    //6.Preenche a Matriz de Bezier
    //
    this->B = iniciaMatrizBezier();
    //
    this->Gx = this->getB() * this->getGx() * this->getB();
    this->Gy = this->getB() * this->getGy() * this->getB();
    this->Gz = this->getB() * this->getGz() * this->getB();
}


// Esse patch acha que é isolado! As curvas que apontam para ele devem ser definidas
// externamente.
BezierPatch :: BezierPatch (	Ponto Pt_00, Ponto Pt_01, Ponto Pt_02, Ponto Pt_03,
                                Ponto Pt_10, Ponto Pt_11, Ponto Pt_12, Ponto Pt_13,
                                Ponto Pt_20, Ponto Pt_21, Ponto Pt_22, Ponto Pt_23,
                                Ponto Pt_30, Ponto Pt_31, Ponto Pt_32, Ponto Pt_33,
                                bool sinal_c1, bool sinal_c2, bool sinal_c3, bool sinal_c4 )
    : CoonsPatch ( ),	Pt03 (Pt_03), Pt13 (Pt_13), Pt23 (Pt_23), Pt33 (Pt_33),
      Pt02 (Pt_02), Pt12 (Pt_12), Pt22 (Pt_22), Pt32 (Pt_32),
      Pt01 (Pt_01), Pt11 (Pt_11), Pt21 (Pt_21), Pt31 (Pt_31),
      Pt00 (Pt_00), Pt10 (Pt_10), Pt20 (Pt_20), Pt30 (Pt_30)
{

    this->sinal_c1 = sinal_c1;
    this->sinal_c2 = sinal_c2;
    this->sinal_c3 = sinal_c3;
    this->sinal_c4 = sinal_c4;

    // 1. Inclui as curvas na lista de curvas de CoonsPatch
    //
    this->curvas.push_back ( new CurvParamBezier ( Pt00, Pt10, Pt20, Pt30 ) );
    this->curvas.push_back ( new CurvParamBezier ( Pt30, Pt31, Pt32, Pt33 ) );
    this->curvas.push_back ( new CurvParamBezier ( Pt03, Pt13, Pt23, Pt33 ) );
    this->curvas.push_back ( new CurvParamBezier ( Pt00, Pt01, Pt02, Pt03 ) );
    //
    // 2. Aloca espaço para as matrizes
    //
    this->U.setZero(1,4);
    this->V.setZero(4,1);
    this->Gx.setZero(4,4);
    this->Gy.setZero(4,4);
    this->Gz.setZero(4,4);
    //
    ////////////////////////////////////

    // 3. Preenche as matrizes geométricas com G de Bezier
    //
    // 2x2 superior esquerdo
    Gx(0,0) = this->Pt00.x; Gx(0,1) = this->Pt01.x;
    Gx(1,0) = this->Pt10.x; Gx(1,1) = this->Pt11.x;
    // 2x2 inferior esquerdo
    Gx(2,0) = this->Pt20.x; Gx(2,1) = this->Pt21.x;
    Gx(3,0) = this->Pt30.x; Gx(3,1) = this->Pt31.x;
    // 2x2 superior direito
    Gx(0,2) = this->Pt02.x; Gx(0,3) = this->Pt03.x;
    Gx(1,2) = this->Pt12.x; Gx(1,3) = this->Pt13.x;
    // 2x2 inferior direito
    Gx(2,2) = this->Pt22.x; Gx(2,3) = this->Pt23.x;
    Gx(3,2) = this->Pt32.x; Gx(3,3) = this->Pt33.x;
    //
    // Gy:
    // 2x2 superior esquerdo
    Gy(0,0) = this->Pt00.y; Gy(0,1) = this->Pt01.y;
    Gy(1,0) = this->Pt10.y; Gy(1,1) = this->Pt11.y;
    // 2x2 inferior esquerdo
    Gy(2,0) = this->Pt20.y; Gy(2,1) = this->Pt21.y;
    Gy(3,0) = this->Pt30.y; Gy(3,1) = this->Pt31.y;
    // 2x2 superior direito
    Gy(0,2) = this->Pt02.y; Gy(0,3) = this->Pt03.y;
    Gy(1,2) = this->Pt12.y; Gy(1,3) = this->Pt13.y;
    // 2x2 inferior direito
    Gy(2,2) = this->Pt22.y; Gy(2,3) = this->Pt23.y;
    Gy(3,2) = this->Pt32.y; Gy(3,3) = this->Pt33.y;
    //
    // Gz:
    // 2x2 superior esquerdo
    Gz(0,0) = this->Pt00.z; Gz(0,1) = this->Pt01.z;
    Gz(1,0) = this->Pt10.z; Gz(1,1) = this->Pt11.z;
    // 2x2 inferior esquerdo
    Gz(2,0) = this->Pt20.z; Gz(2,1) = this->Pt21.z;
    Gz(3,0) = this->Pt30.z; Gz(3,1) = this->Pt31.z;
    // 2x2 superior direito
    Gz(0,2) = this->Pt02.z; Gz(0,3) = this->Pt03.z;
    Gz(1,2) = this->Pt12.z; Gz(1,3) = this->Pt13.z;
    // 2x2 inferior direito
    Gz(2,2) = this->Pt22.z; Gz(2,3) = this->Pt23.z;
    Gz(3,2) = this->Pt32.z; Gz(3,3) = this->Pt33.z;
    //
    //6.Preenche a Matriz de Bezier
    //
    this->B = iniciaMatrizBezier();
    //
    this->Gx = this->getB() * this->getGx() * this->getB();
    this->Gy = this->getB() * this->getGy() * this->getB();
    this->Gz = this->getB() * this->getGz() * this->getB();
}


BezierPatch::BezierPatch ( BezierPatch *antigo ) : CoonsPatch ( antigo )
{
    this->Pt03 = antigo->Pt03;   this->Pt13 = antigo->Pt13;   this->Pt23 = antigo->Pt23;   this->Pt33 = antigo->Pt33;
    this->Pt02 = antigo->Pt02;   this->Pt12 = antigo->Pt12;   this->Pt22 = antigo->Pt22;   this->Pt32 = antigo->Pt32;
    this->Pt01 = antigo->Pt01;   this->Pt11 = antigo->Pt11;   this->Pt21 = antigo->Pt21;   this->Pt31 = antigo->Pt31;
    this->Pt00 = antigo->Pt00;   this->Pt10 = antigo->Pt10;   this->Pt20 = antigo->Pt20;   this->Pt30 = antigo->Pt30;

    this->Gx = antigo->Gx;
    this->Gy = antigo->Gy;
    this->Gz = antigo->Gz;
    this->U = antigo->U;
    this->V = antigo->V;
}

BezierPatch::BezierPatch()
{

}

BezierPatch::~BezierPatch (  )
{
    delete &V;
    delete &U;
}

double BezierPatch::getNumberTriangle() const
{
    return NumberTriangle;
}

void BezierPatch::setNumberTriangle(double value)
{
    NumberTriangle = value;
}
double BezierPatch::getAreaTriangle() const
{
    return areaTriangle;
}

void BezierPatch::setAreaTriangle(double value)
{
    areaTriangle = value;
}

double BezierPatch::getSegmentMedio() const
{
    return segmentMedio;
}

void BezierPatch::setSegmentMedio(double value)
{
    segmentMedio = value;
}

double BezierPatch::getKaMedio() const
{
    return kaMedio;
}

void BezierPatch::setKaMedio(double value)
{
    kaMedio = value;
}

double BezierPatch::getArea() const
{
    return area;
}

void BezierPatch::setArea(double value)
{
    area = value;
}

int BezierPatch::getIdProcess() const
{
    return idProcess;
}

void BezierPatch::setIdProcess(int value)
{
    idProcess = value;
}

int BezierPatch::getId_bezierPatch() const
{
    return id_bezierPatch;
}

void BezierPatch::setId_bezierPatch(int value)
{
    id_bezierPatch = value;
}
