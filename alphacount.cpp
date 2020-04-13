#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include <codecvt>

using namespace std;

int countSubstring(const string& str, const string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != string::npos;
	 offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}

int countLetter(const string& str, const vector<string>& letter)
{
    if(letter.size() < 1) return 0;
    int count = 0;

    //cout << "Counting " << letter[0] << "'s...";
    for(int i = 0; i < letter.size(); i++)
    {
        count += countSubstring(str, letter[i]);
    }
    //cout << count << " found!" << endl;  

    return count;  

}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "Error: You must specify an input file (text)" << endl;
        cout << "  Example:   alphacount.exe Eschilo.txt" << endl;
        cout << "  Important: Filenames may not contain any spaces!!!" << endl;
        return 0;
    }
    
    string ifilename = argv[1];
    string ofilename = "Tabelle.csv"; //argv[2];

    string test = "Ζεὺς μὲν ἀφίκτωρ ἐπίδοι προφρόνως  στόλον ἡμέτερον νάιον ἀρθέντ᾽  ἀπὸ προστομίων λεπτοψαμάθων  Νείλου. Δίαν δὲ λιποῦσαι  5χθόνα σύγχορτον Συρίᾳ φεύγομεν,  οὔτιν᾽ ἐφ᾽ αἵματι δημηλασίαν  ψήφῳ πόλεως γνωσθεῖσαν,  ἀλλ᾽ αὐτογενεῖ φυξανορίᾳ  γάμον Αἰγύπτου παίδων ἀσεβῆ  10'ξονοταζόμεναι.  Δαναὸς δὲ πατὴρ καὶ βούλαρχος  καὶ στασίαρχος τάδε πεσσονομῶν  κύδιστ᾽ ἀχέων ἐπέκρανε,  φεύγειν ἀνέδην διὰ κῦμ᾽ ἅλιον,  15κέλσαι δ᾽ Ἄργους γαῖαν, ὅθεν δὴ  γένος ἡμέτερον τῆς οἰστροδόνου";
    
    // setup letter vectors
    vector<string> alpha {"α","Α","ὰ","ά","ἀ","ἁ","ἂ","ἃ","ἄ","ἅ","ἆ","ἇ","Ἀ","Ἁ","Ἂ","Ἃ","Ἄ","Ἅ","Ἆ","Ἇ","ᾀ","ᾁ","ᾂ","ᾃ","ᾄ","ᾅ","ᾆ","ᾇ","ᾈ","ᾉ","ᾊ","ᾋ","ᾌ","ᾍ","ᾎ","ᾏ","ᾰ","ᾱ","ᾲ","ᾳ","ᾴ","ᾶ","ᾷ","Ᾰ","Ᾱ","Ὰ","Ά","ᾼ"};
    vector<string> beta {"β","Β"};
    vector<string> gamma {"γ","Γ"};
    vector<string> delta {"δ","Δ"};
    vector<string> epsilon {"ε","Ε","ὲ","έ","ἐ","ἑ","ἒ","ἓ","ἔ","ἕ","Ἐ","Ἑ","Ἒ","Ἓ","Ἔ","Ἕ","Ὲ","Έ"};
    vector<string> zeta {"ζ","Ζ"};
    vector<string> eta {"η","Η","ὴ","ή","ἠ","ἡ","ἢ","ἣ","ἤ","ἥ","ἦ","ἧ","Ἠ","Ἡ","Ἢ","Ἣ","Ἤ","Ἥ","Ἦ","Ἧ","ᾐ","ᾑ","ᾒ","ᾓ","ᾔ","ᾕ","ᾖ","ᾗ","ᾘ","ᾙ","ᾚ","ᾜ","ᾝ","ᾞ","ᾟ","ῂ","ῃ","ῄ","ῆ","ῇ","Ὴ","Ή","ῌ"};
    vector<string> theta {"θ","Θ"};
    vector<string> iota {"ι","Ι","ὶ","ί","ἰ","ἱ","ἲ","ἳ","ἴ","ἵ","ἶ","ἷ","Ἰ","Ἱ","Ἲ","Ἳ","Ἴ","Ἵ","Ἶ","Ἷ","ῐ","ῑ","ῒ","ΐ","ῖ","ῗ","Ῐ","Ῑ","Ὶ","Ί","ϊ","Ϊ","ΐ"};
    vector<string> kappa {"κ","Κ"};
    vector<string> lambda {"λ","Λ"};
    vector<string> mu {"μ","Μ"};
    vector<string> nu {"ν","Ν"};
    vector<string> xi {"ξ","Ξ"};
    vector<string> omikron {"ο","Ο","ὸ","ό","ὀ","ὁ","ὂ","ὃ","ὄ","ὅ","Ὀ","Ὁ","Ὂ","Ὃ","Ὄ","Ὅ","Ὸ","Ό"};
    vector<string> pi {"π","Π"};
    vector<string> rho {"ρ","Ρ","ῤ","ῥ","Ῥ"};
    vector<string> sigma {"σ","Σ","ς"};
    vector<string> tau {"τ","Τ"};     
    vector<string> ypsilon {"υ","Υ","ὺ","ύ","ὐ","ὑ","ὒ","ὓ","ὔ","ὖ","ὕ","ὗ","Ὑ","Ὓ","Ὕ","Ὗ","ῠ","ῡ","ῢ","ΰ","ῦ","ῧ","Ῠ","Ῡ","Ὺ","Ύ","ϋ","ΰ","Ϋ"};            
    vector<string> phi {"φ","Φ"};
    vector<string> chi {"χ","Χ"};
    vector<string> psi {"ψ","Ψ"};
    vector<string> omega {"ω","Ω","ώ","ὼ","ὠ","ὡ","ὢ","ὣ","ὤ","ὥ","ὦ","ὧ","Ὠ","Ὡ","Ὢ","Ὣ","Ὤ","Ὥ","Ὦ","Ὧ","ᾠ","ᾡ","ᾢ","ᾣ","ᾤ","ᾥ","ᾦ","ᾧ","ᾨ","ᾩ","ᾪ","ᾫ","ᾬ","ᾭ","ᾮ","ᾯ","ῲ","ῳ","ῴ","ῶ","ῷ","Ὼ","Ώ","ῼ"};    

    // initialize letter counters
    int alphacount = 0;
    int betacount = 0;
    int gammacount = 0;
    int deltacount = 0;
    int epsiloncount = 0;
    int zetacount = 0;
    int etacount = 0;
    int thetacount = 0;
    int iotacount = 0;
    int kappacount = 0;
    int lambdacount = 0;
    int mucount = 0;
    int nucount = 0;
    int xicount = 0;
    int omikroncount = 0;
    int picount = 0;
    int rhocount = 0;
    int sigmacount = 0;
    int taucount = 0;
    int ypsiloncount = 0;
    int phicount = 0;
    int chicount = 0;
    int psicount = 0;
    int omegacount = 0;

    // open input file
    wifstream inputfile(ifilename.c_str(), std::ios::binary); // You need to open the file in binary mode

    // Imbue the file stream with a codecvt facet that uses UTF-16 as the external multibyte encoding
    inputfile.imbue(locale(inputfile.getloc(),
              new codecvt_utf16<wchar_t, 0xffff, consume_header>));

    // ^ We set 0xFFFF as the maxcode because that's the largest that will fit in a single wchar_t
    //   We use consume_header to detect and use the UTF-16 'BOM'

    // The following is not really the correct way to write Unicode output, but it's easy
    std::wstring sLine;
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;

    if(!inputfile.is_open())
    {
        cout << "Error: File " << ifilename << " not found!" << endl;
        return 0;
    }

    // count letters line by line
    int linecount = 1;
    while(getline (inputfile,sLine))
    {

        test = convert.to_bytes(sLine);
        //cout << test << endl;

        cout << "\r" << "Counting letters on line " << linecount++ << flush;
        alphacount += countLetter(test, alpha);
        betacount += countLetter(test, beta);  
        gammacount += countLetter(test, gamma);
        deltacount += countLetter(test, delta); 
        epsiloncount += countLetter(test, epsilon);
        zetacount += countLetter(test, zeta);  
        etacount += countLetter(test, eta);
        thetacount += countLetter(test, theta);
        iotacount += countLetter(test, iota); 
        kappacount += countLetter(test, kappa);
        lambdacount += countLetter(test, lambda);
        mucount += countLetter(test, mu);
        nucount += countLetter(test, nu); 
        xicount += countLetter(test, xi);
        omikroncount += countLetter(test, omikron);  
        picount += countLetter(test, pi);
        rhocount += countLetter(test, rho);    
        sigmacount += countLetter(test, sigma);  
        taucount += countLetter(test, tau);      
        ypsiloncount += countLetter(test, ypsilon);              
        phicount += countLetter(test, phi); 
        chicount += countLetter(test, chi);
        psicount += countLetter(test, psi);    
        omegacount += countLetter(test, omega);  
    }

    // write results to csv file
    ofstream csvfile;
    csvfile.open(ofilename);

    int total = alphacount + betacount + gammacount + deltacount + epsiloncount + zetacount + etacount + thetacount + iotacount
        + kappacount + lambdacount + mucount + nucount + xicount + omikroncount + picount + rhocount + sigmacount
        + taucount + ypsiloncount + phicount + chicount + psicount + omegacount;

    csvfile << "Total;Alpha;Beta;Gamma;Delta;Epsilon;Zeta;Eta;Theta;Iota;Kappa;Lambda;Mu;Nu;Xi;Omikron;Pi;Rho;Sigma;Tau;Ypsilon;Phi;Chi;Psi;Omega;" << endl;
    csvfile << total << ";" << alphacount << ";" << betacount << ";" << gammacount << ";" << deltacount << ";" << epsiloncount << ";" << zetacount << ";" << etacount << ";" << thetacount << ";" << iotacount
        << ";" << kappacount << ";" << lambdacount << ";" << mucount << ";" << nucount << ";" << xicount << ";" << omikroncount << ";" << picount << ";" << rhocount << ";" << sigmacount
        << ";" << taucount << ";" << ypsiloncount << ";" << phicount << ";" << chicount << ";" << psicount << ";" << omegacount << endl;

    csvfile.close();
           
}