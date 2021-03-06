#include "InOutStreams.h"
#include "GlobalVariables.h"

InOutStreams::InOutStreams() {
    logStdOut=NULL;
    outSAM=NULL;
    outBAMfileUnsorted=NULL;
};

InOutStreams::~InOutStreams() {
    
    if (logStdOut!=NULL) logStdOut->flush();
    if (outSAM!=NULL) outSAM->flush();
    
    logStdOutFile.flush();
    outSAMfile.flush();
    
    if (outBAMfileUnsorted!=NULL) {
        bgzf_flush(outBAMfileUnsorted);
        bgzf_close(outBAMfileUnsorted);
    };
    
    if (outBAMfileCoord!=NULL) {
        bgzf_flush(outBAMfileCoord);
        bgzf_close(outBAMfileCoord);
    };    

    
    outChimSAM.flush();
    outChimJunction.flush();    
    logProgress.flush();
    logMain.flush();
    logFinal.flush();
    outLocalChains.flush();
    
    logStdOutFile.close();
    outSAMfile.close();
    outChimSAM.close();
    outChimJunction.close();    
    logProgress.close();
    logMain.close();
    logFinal.close();    
    outLocalChains.close();
    
    
    for (int ii=0;ii<2;ii++) {
        if (outUnmappedReadsStream[ii].is_open()) {
            outUnmappedReadsStream[ii].flush();
            outUnmappedReadsStream[ii].close();
        }
    };
};
   
