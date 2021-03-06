% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/DynComm.R
\docType{methods}
\name{select}
\alias{select}
\alias{DynComm.select}
\title{select(postProcessing, id)}
\usage{
DynComm.select(dyncomm,postProcessing, id)
}
\arguments{
\item{dyncomm}{A DynComm object, if not using the inline version of the 
function call}

\item{postProcessing}{The name of the post processing algorithm. Default 
POSTPROCESSING$NONE. See \code{\link{POSTPROCESSING}}}

\item{id}{The ID of the post processing algorithm. Default value is 1}
}
\value{
FALSE if the algorithm does not exist in the chain. Otherwise, TRUE
}
\description{
This method allows for the selection of which result should be shown. Any of 
the post processing algorithms and the main algorithm can be choosen.
}
\details{
The ID parameter is used to distinguish between several post processing 
algorithms of the same type. It is not required for neither the main 
algorithm nor any post processing algorithm type that only appears one time.

The main algorithm can be selected with POSTPROCESSING$NONE (default value) 
and the ID is ignored. See \code{\link{POSTPROCESSING}} for other available 
algorithms.

If there are no actions defined for post processing, this function fails.
}
\examples{
library(DynComm)
parameters<-matrix(c("e","0.1","w", "FALSE"),ncol=2, byrow=TRUE)
  dc<-DynComm(ALGORITHM$LOUVAIN,CRITERION$MODULARITY,parameters)
  dc$addRemoveEdges(
   matrix(
      c(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,12,13,1,1,1,2,2,2,18,12,19,20,2,3,11,12,4,9,5,9,22)
      ,ncol=2)
  )
  dc$postProcess(
    list(
 	     list(POSTPROCESSING$DENSOPT)
  	)
  )
 dc$select(POSTPROCESSING$DENSOPT)  #selects the results of densopt
 dc$select(POSTPROCESSING$NONE)  #selects the main algorithm results

 dc$postProcess(NULL)  #remove post processing
 ## or just
 ## dc$postProcess()


}
\seealso{
\code{\link{DynComm}} , \code{\link{postProcess}}
}
\author{
poltergeist0
}
