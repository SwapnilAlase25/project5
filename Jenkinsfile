properties([parameters([string(defaultValue: '5', description: 'For the swap program, we need 2 numbers', name: 'FirstNumber', trim: false), string(defaultValue: '10', description: 'For the swap program, we need 2 numbers', name: 'SecondNumber', trim: false)]), pipelineTriggers([cron('H/4 * * * *')])])
def repo_branch = 'master'
def repo_url = 'https://github.com/SwapnilAlase25/project5.git/'
boolean startedByTimerFlag
def call() {
    boolean startedByTimer = false

    def buildCauses = currentBuild.rawBuild.getCauses()

    for (buildCause in buildCauses) {
        if ("${buildCause}".contains("hudson.triggers.TimerTrigger\$TimerTriggerCause")) {
            startedByTimer = true
        }
    }
    return startedByTimer
}

node { 
    
startedByTimerFlag = this.call()
    
    try{
    stage("Get project"){
        git branch: repo_branch, url: repo_url
        }
    }catch(e){
        echo "Get project failed! "
        throw e
    }
    
    try{
        stage('Compiling') {
            echo "compiling swap program"
            sh 'gcc --version'
            if(startedByTimerFlag == false){
                sh "gcc swap.c -o swap"
            }
            sh "gcc hello_world.c -o hello"
            //print "Hello ${name}"
        }
    }catch(e){
        echo "Compiling stage failed! "
        throw e
    }
   
    try{
        stage('Testing') {
            echo "Testing swap program"
            if(startedByTimerFlag == false){
                sh "./swap ${params.FirstNumber} ${params.SecondNumber}"
            }
            sh "./hello"
        }
     }catch(e){
            echo "Testing stage failed! "
             throw e
    }
    
    try{
        stage('Archiving') {
            echo "Archiving swap program output" 
            sh "./swap ${params.FirstNumber} ${params.SecondNumber} > log.txt" 
            archiveArtifacts artifacts: 'log.txt', fingerprint: true
            }
     }catch(e){
        echo "Archiving stage failed! "
        throw e
    }
    
       
 }

